#include <QDebug>
#include <QFile>
#include <QTime>

#include "ut.h"
 
Ut::Ut(QWidget *parent) : QDialog(parent)
{
qDebug() << "start Ut";
	ui.setupUi(this);
	filename = ui.input_file_name->text();
	connect(ui.go, SIGNAL(clicked()), this, SLOT(read()));

qDebug() << "stop Ut";
}

Question::Question(QString s)
{
	text = s;
}

Question::Answer::Answer(QString s, const bool corr)
{
	text = s;
	correct = corr;
}

bool Ut::read_data()
{
	filename = ui.input_file_name->text();
qDebug() << "begin read_data " << filename;

	QFile inp(filename);
	if (!inp.open(QFile::ReadOnly))
	{
qDebug() << "ERROR!";
		return false;		
	}
	QTextStream text(&inp);
	text.setCodec("UTF-8");
	while (!text.atEnd())
	{
		QString s = text.readLine();
		if (s.length() > 3 && s.mid(1,3) == "eng")
		{
			QString q;
			while (!s.isEmpty()) 
			{
				s = text.readLine();
				q += (s + "\n");
			}
			test.push_back(Question(q));
		}	
		else if (!s.isEmpty() && (s[0] == '-' || s[0] == '+'))
		{
			test[test.size() - 1].ans.push_back(Question::Answer(s.mid(2), s[0] == '+'));
			
		}
	}
	inp.close();
	for (int i=0; i < test.size(); i++)
	{
qDebug() << test[i].get_text() << test[i].ans.size();	
		for (int j=0; j < test[i].ans.size(); j++)
qDebug() << test[i].ans[j].get_text();
	}
qDebug() << "end read_data";
	return true;
}

void Ut::make_one_test()
{
	int i = 0;
	one_test.clear();
	v_one_test.clear();
qDebug() << ui.nnumber->value();	
	while( i < ui.nnumber->value())
	{	int num = qrand()%test.size();  // index in QVector<Question> test		
		if (!one_test.contains(num)) 
		{
			one_test.insert(num);
			v_one_test.push_back(num);
			i++;		
			test[num].set_ans.clear();
			test[num].v_set_ans.clear();
			int j = 0;
			while (j < 4)
			{
				int nums = qrand()%test[num].ans.size();
qDebug() << i << ":" << num << j << ":" << nums;				
				if (!test[num].set_ans.contains(nums))
				{
					test[num].set_ans.insert(nums); 
					test[num].v_set_ans.push_back(nums);
					j++;
				}
			}
		}

	}

qDebug() << ui.nnumber->value() << one_test;

 	QSetIterator<int> ii(one_test);
 	while (ii.hasNext())
	{
		int k = ii.next();
qDebug() << test[k].get_text();
		QSetIterator<int> jj(test[k].set_ans);
 		while (jj.hasNext())
		{
			int l = jj.next();
qDebug() << test[k].ans[l].get_text();	
		}
	}
qDebug() << qrand()%100;
}

void Ut::write_one_test(int num_test, QTextStream& out, QTextStream& tab)
{
	QString abcd[4] = {"{\\bf a)}\\ ", "{\\bf b)}\\ ", "{\\bf c)}\\ ", "{\\bf d)}\\ "}; 


		out << "\\newpage\\thispagestyle{empty}\\par \n\\hrule \n\\begin{center}\n"
			<< "{\\bf\\large \\fbox{2013/2014}}\\hfill "
 			<< "{\\bf\\large\\verb|" << ui.test_no->currentText();
		out << "|}\n \\hfill{\\bf\\large \\fbox{ NBU }}\\\\ \n"
	    		<< "{\\bf\\large " << ui.title->currentText() << "}\\\\[4pt]\n"
	    		<< "{\\bf \\large \\fbox{ " << ui.test_no->currentText().left(4) << " \\ \\ No. ";
       		out << num_test << "}}\\\\ \n" << "\\end{center}\\par\n \\vspace{-4mm}\n"
            		<< "\\begin{multicols}{2}\n";

	int i = 0, numplus = 0;
//	QSetIterator<int> ii(one_test);
// 	while (ii.hasNext())
	for (int ii=0; ii < v_one_test.size(); ii++) 
	{
		i++;
		
//		int k = ii.next();
		int k = v_one_test[ii];
		out << "\\par\\smallskip\\hrule\\par\\medskip\n\n"
			<< "%%%% " << k+1 << " %%%%\n" 
	         	<< "{\\bf " << i << ". }\\ " << test[k].get_text();
		tab << " & " << ii+1 << ".";
	
		int j = 0;        // 0,1,2,3
//		QSetIterator<int> jj(test[k].set_ans);
// 		while (jj.hasNext())
		for (int jj=0; jj < test[k].v_set_ans.size(); jj++)
		{
//			int l = jj.next();
			int l = test[k].v_set_ans[jj];			 
			QString corr =  test[k].ans[l].get_correct();
			out << "%%% " << corr << l+1 << " %%%\n"
				<< abcd[j] << test[k].ans[l].get_text() << "\n\n";
			if (corr == "+") 
			{
				tab << static_cast<char>('a' + j);
				numplus++;
			}
			test[k].ans[l].itest.push_back(Three(num_test, i, j));
			j++;	
		}
	}
	out << "\\end{multicols}\n\n";
	tab << " &(" << numplus << ")\\\\ \\hline\n";	
}

void Ut::write_tests()
{
qDebug() << "write out.tex and tab.tex";
	QFile outfile("out.tex");
	outfile.open(QIODevice::WriteOnly);
	QTextStream out(&outfile);
	out.setCodec("UTF-8");

	QFile tabfile("tab.tex");
	tabfile.open(QIODevice::WriteOnly);
	QTextStream tab(&tabfile);
	tab.setCodec("UTF-8");

	QTime now = QTime::currentTime();
	qsrand(now.msec());

	int seed = 1000 + qrand()%8000;

	for (int i=0; i<ui.number_of_tests->value(); i++)
	{
		make_one_test();
		seed += 7;
		out << "\n%%%%% " << i+1 << " %%%%\n";
		tab << seed;
		write_one_test(seed, out, tab);
	}
	outfile.close();
	tabfile.close();
}

void Ut::write_data()
{
qDebug() << "write data.tex";
	QFile datafile("data.tex");
	datafile.open(QIODevice::WriteOnly);
	QTextStream data(&datafile);
	data.setCodec("UTF-8");
	for (int i=0; i < test.size(); i++)
	{
		data << "%%%%% " << i << " %%%%%\n";
		data << test[i].get_text();
		for (int j=0; j < test[i].ans.size(); j++)
		{
			data << "%%% " << test[i].ans[j].itest.size() << " ";
			for (int k=0; k < test[i].ans[j].itest.size(); k++)
				data << test[i].ans[j].itest[k].th1 << "-"
					<< test[i].ans[j].itest[k].th2 << "-"										<< test[i].ans[j].itest[k].th3 << "; ";

			data << " %%%\n";
			data <<  test[i].ans[j].get_correct() << " "
				<< test[i].ans[j].get_text() << "\n\n";
		}	
	}
	datafile.close();
}

void Ut::read()
{
qDebug() << "read";
	read_data();
	make_one_test();
	write_tests();
	write_data();
	ui.go->setText("DONE");
	ui.go->update();
	ui.go->setDisabled(true);
}
