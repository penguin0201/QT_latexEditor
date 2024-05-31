#ifndef MYLATEXHIGHLIGHTER_H
#define MYLATEXHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
#include <QTextDocument>

class myLatexHighlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    myLatexHighlighter();
};

#endif // MYLATEXHIGHLIGHTER_H
