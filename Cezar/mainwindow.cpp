#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <fstream>
#include <QFileDialog>
using namespace std;
string input,s,output;
int  key;
QString infile, outfile;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_3_clicked()
{
    infile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    input = infile.toStdString();

    ifstream in(input.c_str());
   getline(in,s);
   in.close();
    ui->lineEdit_3->setText(QString::fromStdString(s));

}
void MainWindow::on_pushButton_4_clicked()
{
    outfile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    output = outfile.toStdString();

   //ifstream out(output.c_str());
 // getline(out,s);
   //out.close();
   //ui->lineEdit_3->setText(QString::fromStdString(s));

}
void MainWindow::on_pushButton_clicked()
{
     output = outfile.toStdString();
      string result;
       ifstream in(input.c_str());
     if (key > 26)
         key = key % 26; //Вычисление сдвига
     string s; //Строка считанная из файла
    getline(in, s);


     in.close();

     for (int i = 0; i < s.length(); i++)
     {
         if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
             result += s[i];
         if (((int)(s[i]) >= 97) && ((int)(s[i]) <= 122))
         {
             if ((int)(s[i]) + key > 122)
                 result += (char)((int)(s[i]) + key - 26);
             else
                 result += (char)((int)(s[i]) + key);
         }
         if (((int)(s[i]) >= 65) && ((int)(s[i]) <= 90))
         {
             if ((int)(s[i]) + key > 90)
                 result += (char)((int)(s[i]) + key - 26);
             else
                 result += (char)((int)(s[i]) + key);
         }
     }
     ui->label->setText(QString::fromStdString(result));
     ofstream out(output.c_str());
      out<<result;
     out.close();
}

void MainWindow::on_lineEdit_2_editingFinished()
{

  key=ui->lineEdit_2->text().toInt(0, 10);
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    //QString filename;
   //filename = ui->lineEdit_3->text();
   //input = filename.toStdString();

}

void MainWindow::on_pushButton_2_clicked()
{
    //infile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
   output = outfile.toStdString();
    string result = "";
   ifstream in(input.c_str());

    if (key > 26)
            key = key % 26;

       string s;
        getline(in, s);

        in.close();

        for (int i = 0; i < s.length(); i++)
        {
            //Если не латиница
            if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
                result += s[i];
            //Если буква является строчной
            if (((int)(s[i]) >= 97) && ((int)(s[i]) <= 122))
            {
                if ((int)(s[i]) - key < 97)
                    result += (char)((int)(s[i]) - key + 26);
                else
                    result += (char)((int)(s[i]) - key);
            }
            //Если буква является прописной
            if (((int)(s[i]) >= 65) && ((int)(s[i]) <= 90))
            {
                if ((int)(s[i]) - key < 65)
                    result += (char)((int)(s[i]) - key + 26);
                else
                    result += (char)((int)(s[i]) - key);
            }
        }
            ui->label->setText(QString::fromStdString(result));
            ofstream out(output.c_str());
             out<<result;
            out.close();
}
