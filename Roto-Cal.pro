# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE38E8E6E

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

SOURCES += main.cpp mainwindow.cpp \
    calendarwidget.cpp \
    calendarmenu.cpp \
    clickablelabel.cpp \
    rotaryview.cpp \
    rotatablelabel.cpp \
    datedisplay.cpp \
    monthview.cpp \
    calobject.cpp \
    dayview.cpp \
    todoview.cpp \
    listview.cpp \
    daylabel.cpp \
    monthlabel.cpp
HEADERS += mainwindow.h \
    calendarwidget.h \
    calendarmenu.h \
    clickablelabel.h \
    rotaryview.h \
    rotatablelabel.h \
    datedisplay.h \
    monthview.h \
    calobject.h \
    dayview.h \
    todoview.h \
    listview.h \
    daylabel.h \
    monthlabel.h
FORMS += mainwindow.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/AndroidManifest.xml \
    android/version.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/values-el/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-ru/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-pl/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-et/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/values-it/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-id/strings.xml

RESOURCES += \
    Resources.qrc
