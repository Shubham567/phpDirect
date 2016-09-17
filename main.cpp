#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QSettings>
#include <cstdlib>
#include <QMessageBox>
#include <selection.h>
#include <QDebug>
#include <cstring>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(argc<2)
    {
        w.show();

        return a.exec();
    }
    else
    {
        QSettings *pref;
        pref=new QSettings("SS7 Workstation","phpDirect");
        QString br=pref->value("directLoc/browser").toString();
        QString ed=pref->value("directLoc/editor").toString();
        QString se=pref->value("directLoc/server").toString();

        for(int i=0;i<(signed)strlen(argv[1]);i++)
        {
            if(argv[1][i]=='\\')
                argv[1][i]='/';
        }

        QString fileName(argv[1]);

        if(br.isEmpty()||ed.isEmpty()||se.isEmpty())
        {
            QMessageBox::warning(&w,"Error : phpDirect","First configure the program and enter your browser, editor and server folder preferences.");
        }
        else
        {
            int opt=0;
            selection *dialog;
            dialog=new selection(&opt,&w);
            dialog->exec();
          //  system("echo off");


            if(opt==1)
            {
                char str[500];
                str[0]=34;
                str[1]=34;
                str[2]=0;
                QString opstr;
                opstr.append(br);

                strcat(str,opstr.toLocal8Bit().data());
                int len=(int)strlen(str);
                str[len]=34;
                str[len+1]=' ';
                str[len+2]=34;
                str[len+3]=0;

                if(fileName.contains(se))
                {

                    char pop[]="http://localhost/";
                    strcat(str,pop);
                    int j=(int)strlen(str);
                    for(int i=se.length()+1;i<fileName.length();i++)
                    {
                        str[j++]=fileName.at(i).toLatin1();
                    }
                    str[j]=34;
                    str[j+1]=34;
                    str[j+2]=0;

                     qDebug()<<str;

                }
                else
                {
                    QMessageBox::warning(&w,"Warning : phpDirect","File may not execute as php in browser! Not in php server location.");
                    char *toAdd=fileName.toLocal8Bit().data();
                    for(int i=0;i<(int)strlen(toAdd);i++)
                    {
                        if(toAdd[i]=='/')
                            toAdd[i]='\\';
                    }
                    strcat(str,toAdd);

                    qDebug()<<str;
                    int j=(int)strlen(str);
                    str[j]=34;
                    str[j+1]=34;
                    str[j+2]=0;



                }

                system(str);
            }
            else if(opt==2)
            {
                char str[500];
                str[0]=34;
                str[1]=34;
                str[2]=0;
                QString opstr;
                opstr.append(ed);

                strcat(str,opstr.toLocal8Bit().data());
                int len=(int)strlen(str);
                str[len]=34;
                str[len+1]=' ';
                str[len+2]=34;
                str[len+3]=0;

                strcat(str,fileName.toLocal8Bit().data());
                int j=(int)strlen(str);
                str[j]=34;
                str[j+1]=34;
                str[j+2]=0;

               system(str);
               system("exit");
            }

        }
        return 0;
    }

}
