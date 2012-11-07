/*
 * time.h
 *
 *  Created on: Sep 12, 2012
 *      Author: Gerron
 */

#ifndef TIME1_H_
#define TIME1_H_

#include <QtCore>


//! Time class.
/*!
Class to contain time as int hour, int minute, bool am, bool pm
*/
class Time1{
	protected:

	private:
        int hour;       /**< hour as int */
        int minute;     /**< minute as int */
        bool am;        /**< am as bool */
        bool pm;        /**< pm as bool */

	public:
		//Constructors

        //! Time1 constructor.
       /*!
       Time1's default constructor.
       \sa Time1(int hour, int minute, bool am, bool pm)
       */
        Time1();

        //! Time1 constructor.
       /*!
       Time1's constructor.
       \sa Time1()
       */
        Time1(int hour, int minute, bool am, bool pm);

		//Functions

        //! A editTime.
       /*!
       \param a a hour integer argument.
       \param s a minute integer argument.
       */
        void editTime(int hour, int minute, bool am, bool pm);

        //! Display Time as a String.
       /*!
       */
		std::string displayTime();

		//Getters and Setters
        //! Returns boolean value for am.
       /*!
       \return boolean
       */
		bool isAm() const {
			return am;
		}

        //! Set Am.
       /*!
       \param am boolean argument.
       */
		void setAm(bool am) {
			this->am = am;
		}

        //! Get Time's Hour.
       /*!
       \return hour
       */
        int getHour() const {
			return hour;
		}

        //! Set Time's Hour.
       /*!
       \param hour integer argument
       */
		void setHour(int hour) {
			this->hour = hour;
		}

        //! Get Time's minute.
       /*!
       \return minute
       */
        int getMinute() const {
			return minute;
		}

        //! Set Time's minute.
       /*!
       \param hour integer argument
       */
		void setMinute(int minute) {
			this->minute = minute;
		}

        //! Returns boolean value for pm.
       /*!
       \return bool
       */
        bool isPm() const {
			return pm;
		}

        //! Set boolean value for pm.
       /*!
       \param pm boolean argument
       */
		void setPm(bool pm) {
			this->pm = pm;
		}

};

#endif /* TIME1_H_ */
