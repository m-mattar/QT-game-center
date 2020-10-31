#ifndef ROLLINGBG_H
#define ROLLINGBG_H

#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include <QPainter>

class RollingBg : public QWidget {
    Q_OBJECT
public:
    explicit RollingBg(QWidget *parent = nullptr);
    ~RollingBg();

    QTimer * timer;

protected:
    void paintEvent(QPaintEvent * event) override;

private:
    QPixmap background;
    int offset;
    int height;
    int width;

signals:

};

#endif // ROLLINGBG_H
