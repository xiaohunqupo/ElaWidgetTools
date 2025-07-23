#ifndef ELATREEVIEWPRIVATE_H
#define ELATREEVIEWPRIVATE_H

#include <QObject>

#include "ElaStdAfx.h"

class ElaTreeView;
class ElaTreeViewStyle;
class ElaTreeViewPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaTreeView)
public:
    explicit ElaTreeViewPrivate(QObject* parent = nullptr);
    ~ElaTreeViewPrivate();

private:
    ElaTreeViewStyle* _treeViewStyle{nullptr};
};

#endif // ELATREEVIEWPRIVATE_H
