#include "highlighter.h"

//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatterns[] = {
        QStringLiteral("\\bsqrt\\b"), QStringLiteral("\\bfrac\\b"), QStringLiteral("\\bequation\\b"),
        QStringLiteral("\\blabel\\b"), QStringLiteral("\\bitemize\\b"), QStringLiteral("\\benumerate\\b"),
        QStringLiteral("\\blarge\\b"), QStringLiteral("\\bsmall\\b"), QStringLiteral("\\busepackage\\b"),
        QStringLiteral("\\bunderline\\b"), QStringLiteral("\\btexttt\\b"), QStringLiteral("\\btextsf\\b"),
        QStringLiteral("\\btextrm\\b"), QStringLiteral("\\btextbf\\b"), QStringLiteral("\\btextsc\\b"),
        QStringLiteral("\\btextsl\\b"), QStringLiteral("\\btextit\\b"), QStringLiteral("\\bsubsubsection\\b"),
        QStringLiteral("\\bsubsection\\b"), QStringLiteral("\\bsection\\b"), QStringLiteral("\\btoday\\b"),
        QStringLiteral("\\bmaketitle\\b"), QStringLiteral("\\bdata\\b"), QStringLiteral("\\bauthor\\b"),
        QStringLiteral("\\btitle\\b"), QStringLiteral("\\breport\\b"), QStringLiteral("\\barticle\\b"),
        QStringLiteral("\\bsum\\b"), QStringLiteral("\\bint\\b"), QStringLiteral("\\bpi\\b"),
        QStringLiteral("\\bdocument\\b"), QStringLiteral("\\bend\\b"), QStringLiteral("\\bbegin\\b")
    };
    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
        //! [0] //! [1]
    }
    //! [1]

    //! [2]
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.format = classFormat;
    highlightingRules.append(rule);
    //! [2]

    //! [3]
    singleLineCommentFormat.setForeground(Qt::red);
    rule.pattern = QRegularExpression(QStringLiteral("%[^\n]*"));
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::red);
    //! [3]

    //! [4]
    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression(QStringLiteral("{.*}"));
    rule.format = quotationFormat;
    highlightingRules.append(rule);
    //! [4]

    //! [5]
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);
    //! [5]

    //! [6]
    commentStartExpression = QRegularExpression(QStringLiteral(" /\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}
//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    //! [7] //! [8]
    setCurrentBlockState(0);
    //! [8]

    //! [9]
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    //! [9] //! [10]
    while (startIndex >= 0) {
        //! [10] //! [11]
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
//! [11]
