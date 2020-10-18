/** \file user.h
 * \brief Contains a class that represents a user/admin.
 */

#ifndef USER_H
#define USER_H

#include <QString>


/**
 * \brief A user.
 * The "user" class has no private members:
 *
 * The user class has a name and a boolean isAdmin member.
 * If the user's isAdmin == true, then the user is considered
 * an administrator and gains administrator functionality within the program.
 */
struct user
{
    /** QString
     * \brief name
     * A name for the user.
     */
    QString name;

    /** bool
     * \brief isAdmin
     * isAdmin == True if the user has administrator priveliges.
     * isAdmin == False if the user does not have administrator priveliges.
     */
    bool isAdmin;

    /** @private
     */
    bool isMonkey;
};

#endif // USER_H
