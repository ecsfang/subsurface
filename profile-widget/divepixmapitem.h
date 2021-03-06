// SPDX-License-Identifier: GPL-2.0
#ifndef DIVEPIXMAPITEM_H
#define DIVEPIXMAPITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class DivePixmapItem : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
	Q_PROPERTY(qreal opacity WRITE setOpacity READ opacity)
	Q_PROPERTY(QPointF pos WRITE setPos READ pos)
	Q_PROPERTY(qreal x WRITE setX READ x)
	Q_PROPERTY(qreal y WRITE setY READ y)
public:
	DivePixmapItem(QGraphicsItem *parent = 0);
};

class DiveButtonItem : public DivePixmapItem {
	Q_OBJECT
public:
	DiveButtonItem(QGraphicsItem *parent = 0);
protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
	void clicked();
};

class CloseButtonItem : public DiveButtonItem {
	Q_OBJECT
public:
	CloseButtonItem(QGraphicsItem *parent = 0);
public slots:
	void hide();
	void show();
};

class DivePictureItem : public DivePixmapItem {
	Q_OBJECT
	Q_PROPERTY(qreal scale WRITE setScale READ scale)
public:
	DivePictureItem(QGraphicsItem *parent = 0);
	void setPixmap(const QPixmap& pix);
public slots:
	void settingsChanged();
#ifndef SUBSURFACE_MOBILE
	void removePicture();
#endif
	void setFileUrl(const QString& s);
protected:
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	QString fileUrl;
	QGraphicsRectItem *canvas;
	QGraphicsRectItem *shadow;
	DiveButtonItem *button;
};

#endif // DIVEPIXMAPITEM_H
