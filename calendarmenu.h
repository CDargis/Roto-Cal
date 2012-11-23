#ifndef CALENDARMENU_H
#define CALENDARMENU_H

#include <QWidget>
#include <QLabel>

#include "selectablelabel.h"

/**
 * @brief The CalendarMenu class.
 * This class encapsulates the menu located at the top of the screen.
 * @author Chris Dargis
 */
class CalendarMenu : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief CalendarMenu constructor
     * @param xOffset The x offset of the menu
     * @param yOffset The y offset of the menu
     * @param menuWidth The width of the menu
     * @param menuHeight The height of the menu
     * @param parent A poitner to the object's parent
     */
    explicit CalendarMenu(int xOffset, int yOffset, int menuWidth, int menuHeight, QWidget *parent = 0);
    /**
     * @brief getMenuWidth get the width of the menu
     * @return the width of the menu
     */
    const int& getMenuWidth() { return menuWidth; }
    /**
     * @brief getLabelWidth get the width of a label
     * @return the width of one menu item
     */
    const int& getLabelWidth() { return labelWidth; }
    /**
     * @brief get the height of the menu
     * @return the height of the menu
     */
    const int& getMenuHeight() { return menuHeight; }
signals:
    /**
     * @brief This signal is emitted when a label is clicked
     * @param The index of the label that was clicked
     */
    void labelClicked(int pageIndex);
public slots:
    /**
     * @brief slotMonthLabelClicked slot for month label click
     */
    void slotMonthLabelClicked();
    /**
     * @brief slotDayLabelClicked slot for day label click
     */
    void slotDayLabelClicked();
    /**
     * @brief slotDetailLabelClicked slot for detail label click
     */
    void slotDetailLabelClicked();
private:
    /**
     * @brief menuWidth Integer representation of the width of the menu in pixels
     */
    int menuWidth;
    /**
     * @brief labelWidth Integer representation of the width of a label in pixels
     */
    int labelWidth;
    /**
     * @brief menuHeight Intgeger representation of the height of the menu in pixels
     */
    int menuHeight;

    /**
     * @brief monthLabel A pointer to a selectable label object that represents the month
     */
    SelectableLabel* monthLabel;
    /**
     * @brief dayLabel A pointer to a selectable label object that represents the day
     */
    SelectableLabel* dayLabel;
    /**
     * @brief detailLabel A pointer to a selectable label object that represents the detail
     */
    SelectableLabel* detailLabel;
};

#endif // CALENDARMENU_H
