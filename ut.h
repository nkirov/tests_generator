#ifndef MENU_H
#define MENU_H

#include <QString>
#include <QVector>
#include <QSet>
#include "ui_ut.h"

class Three
{
	public:
	Three(int i1, int i2, int i3)
		{ th1 = i1; th2 = i2; th3 = i3; }
	Three() {}
	int th1, th2, th3;
};

class Question
{
	int num;
	QString text;
public:
	class Answer
	{
		QString text;
		bool correct;
		int num; 
	public:
		Answer(QString, const bool);
		Answer() {};
		QString get_text() const { return text; }
		QString get_correct() const 
			{ return correct?"+":"-"; }
		QVector<Three> itest;
	};
	Question(QString);
	Question() {};
	QVector<Answer> ans;
	QSet<int> set_ans;
	QVector<int> v_set_ans;
	QString get_text() const { return text; }
};
	
class Ut : public QDialog
{
	Q_OBJECT
	public:
		Ut(QWidget *parent = 0);
	private:
		Ui::ut ui;
	
		QString filename;
		bool read_data();
		QVector<Question> test;
		void make_one_test();
		QSet<int> one_test;
		QVector<int> v_one_test;
		void write_one_test(int, QTextStream&, QTextStream&);
		void write_tests();
		void write_data();
	public slots:
		void read();
};
#endif
