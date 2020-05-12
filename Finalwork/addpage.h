 #ifndef ADDPAGE_H
#define ADDPAGE_H
#include <QWidget>
#include<friends.h>
#include<workmate.h>
namespace Ui {
class addpage;
}
class addpage : public QWidget
{
    Q_OBJECT

public:
    explicit addpage(QWidget *parent = nullptr);
    ~addpage();
signals:
    void backtomain();
private:
    Ui::addpage *ui;
};
#endif // ADDPAGE_H
