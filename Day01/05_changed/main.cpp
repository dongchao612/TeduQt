#include <QApplication>
#include <QDialog>
#include <QSlider>
#include <QSpinBox>

int main(int argc,char** argv)
{
	//创建QT应用程序对象
	QApplication app(argc,argv);

	QDialog parent;
    	parent.resize(320,240);

	//创建水平滑块
	QSlider slider(Qt::Horizontal,&parent);
	slider.move(20,100);
	slider.setRange(0,100);

	//创建选值框
	QSpinBox spinbox(&parent);
	spinbox.move(220,100);
	spinbox.setRange(0,100);

	//滑块滑动选值框的数值随之改变
	QObject::connect(&slider,SIGNAL(valueChanged(int)),&spinbox,SLOT(setValue(int)));

	//选值框的数值改变滑块随之改变
	QObject::connect(&spinbox,SIGNAL(valueChanged(int)),&slider,SLOT(setValue(int)));


	parent.show();
	return app.exec();

}
