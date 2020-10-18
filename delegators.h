/** \file city.h
 * \brief Contains two delegator classes for user input validation in QTableWidgets.
 */

#ifndef DELEGATORS_H
#define DELEGATORS_H

#include <QItemDelegate>
#include <QLineEdit>

/**
 * \brief Delegates distance input.
 */
/*! Prevents users from inputting nonsense into the distance fields. A distance will always be an integer between 0–2147483647
 */
class distance_delegator
        : public QItemDelegate
{
public:
    /**
     * @brief createEditor
     * @param parent Used to control how the editor widget appears.
     * @param option Used to control how the editor widget appears.
     * @param index Specified index to edit.
     * @return The widget used to edit the item specified by index for editing.
     */
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option,
                      const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);
        // Set validator
        QIntValidator *validator = new QIntValidator(0, 2147483647, lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};


/**
 * \brief Delegates price input.
 */
/*! Prevents users from inputting nonsense into the price fields. A price will always be a number between 0–2147483647 with only 2 mantissa values.
 */
class price_delegator
        : public QItemDelegate
{
public:
    /**
     * @brief createEditor
     * @param parent Used to control how the editor widget appears.
     * @param option Used to control how the editor widget appears.
     * @param index Specified index to edit.
     * @return The widget used to edit the item specified by index for editing.
     */
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option,
                      const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);
        // Set validator
        QDoubleValidator *validator = new QDoubleValidator(0, 2147483647, 2, lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};

#endif // DELEGATORS_H
