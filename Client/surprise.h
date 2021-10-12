#ifndef SURPRISE_H
#define SURPRISE_H

#include <QGraphicsRectItem>

/**
 * @brief The surprise class creates surprises
 */
class surprise: public QGraphicsRectItem
{
public:
    surprise(QGraphicsItem* parent=NULL);
};

#endif // SURPRISE_H
