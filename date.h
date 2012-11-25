/*
 * date.h
 *
 *  Created on: Sep 12, 2012
 *      Author: Gerron
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>

/**
 * @brief Date class containing day, month, and year
 * @author Gerron Thurman
*/
class Date{

	protected:

	private:
        short int day;      /**< short int for day */
        short int month;    /**< short int for month */
        short int year;     /**< short int for year */

	public:

       //! Enumerator Month.
       /*! enum for months of the year. */
		enum Month{		//Enumerators for months
            JANUARY = 1,    /*!< Enum value January. */
            FEBRUARY,       /*!< Enum value February. */
            MARCH,          /*!< Enum value March. */
            APRIL,          /*!< Enum value April. */
            MAY,            /*!< Enum value May. */
            JUNE,           /*!< Enum value June. */
            JULY,           /*!< Enum value July. */
            AUGUST,         /*!< Enum value August. */
            SEPTEMBER,      /*!< Enum value September */
            OCTOBER,        /*!< Enum value October. */
            NOVEMBER,       /*!< Enum value November. */
            DECEMBER        /*!< Enum value December. */
		};

		//Constructors

       //! Date default constructor.
       /*!
       */
		Date();

       //! Date constructor.
       /*!
       Date constructor taking day, month, year as integers.
       */
		Date(int day, int month, int year);

		//Functions

        //! Edit Date.
       /*!
       \param day an integer argument.
       \param month an integer argument.
       \param year an integer argument()
       */
		void editDate(int day, int month, int year);

        //! Display date as numeric or using enum.
       /*!
       \param numeric as a bool argument.
       \return date as string
       */
		std::string displayDate(bool numeric);

		//Getters & Setters

        //! Get day.
       /*!
       \return day as integer
       */
		int getDay() const {
			return day;
		}

        //! Set day.
       /*!
       \param day as integer argument
       */
		void setDay(int day) {
			this->day = day;
		}

        //! Get month.
       /*!
       \return month as integer
       */
		int getMonth() const {
			return month;
		}

        //! Set month.
       /*!
       \param month as integer argument
       */
		void setMonth(int month) {
			this->month = month;
		}

        //! Get year.
       /*!
       \return year as integer
       */
		int getYear() const {
			return year;
		}

        //! Set year.
       /*!
       \param year as integer argument
       */
		void setYear(int year) {
			this->year = year;
		}

};

#endif /* DATE_H_ */

