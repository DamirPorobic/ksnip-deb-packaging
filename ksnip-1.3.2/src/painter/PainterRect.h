/*
 * Copyright (C) 2017 Damir Porobic <https://github.com/damirporobic>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef PAINTERRECT_H
#define PAINTERRECT_H

#include "PainterBaseItem.h"

class PainterRect : public PainterBaseItem
{
public:
    PainterRect(QPointF pos, QPen attributes, bool filled = 0);
    virtual QRectF boundingRect() const;
    virtual void addPoint(QPointF pos, bool modifier = 0);
    virtual void moveTo(QPointF newPos);
    virtual bool containsRect(QPointF topLeft, QSize size) const;

private:
    QRectF mRect;
    bool   mFilled;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // PAINTERRECT_H
