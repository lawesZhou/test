#include <unistd.h>
#include <stdio.h>

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton> 

class Employee : public QObject
{
	public:
		Employee() { mySalary = 0; }
		int salary() const { return mySalary; }
	public slots:
		void setSalary(int newSalary);
	signals:
		void salaryChanged(int newSalary);
	private:
		int mySalary;
};

void Employee::setSalary(int newSalary)
{
	if (newSalary != mySalary) {
		printf("newsalary = %d\n", newSalary);
		mySalary = newSalary;
		emit salaryChanged(mySalary);
	}
}

void Employee::salaryChanged(int newSalary)
{
}

const char *click()
{
	printf("\n%s\n", SIGNAL(clicked()));
	printf("\n%s\n", SIGNAL(quit()));
	return SIGNAL(clicked());
}

int main(int argc, char *argv[])
{

	QApplication app(argc, argv); 

	Employee *smith = new Employee;
	QWidget *window = new QWidget;
	window->setWindowTitle("test");
	QLabel *label = new QLabel("Hello Qt!");

	label->show();

	//	sleep(3);

	QPushButton *button = new QPushButton("Quit");

	//QObject::connect(button, click(), &app, SLOT(quit()));
	smith->setSalary(5);
	QObject::connect(smith, "2Employee::setSalary(6)" QLOCATION, &app, SLOT(quit()));

	button->show();
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(label);
	layout->addWidget(button);

	window->setLayout(layout);
	window->show();
	return app.exec();
}
