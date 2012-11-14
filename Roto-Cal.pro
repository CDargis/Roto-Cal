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

# Input
HEADERS += \
           calendarmenu.h \
           calendarwidget.h \
           calobject.h \
           cmp_event_day.h \
           cmp_event_month.h \
           cmp_event_set.h \
           cmp_event_year.h \
           date.h \
           datedisplay.h \
           daylabel.h \
           dayview.h \
           detailview.h \
           event.h \
           event_set.h \
           mainwindow.h \
           monthlabel.h \
           monthview.h \
           rotaryview.h \
           rotatablelabel.h \
           serialization.h \
           time1.h \
           time_t_read.h \
    saveeventwidget.h \
    selectablelabel.h \
    clickablelabel.h \
    calendarlistitem.h
FORMS += mainwindow.ui
SOURCES += \
           calendarmenu.cpp \
           calendarwidget.cpp \
           calobject.cpp \
           cmp_event_day.cpp \
           cmp_event_month.cpp \
           cmp_event_set.cpp \
           cmp_event_year.cpp \
           date.cpp \
           datedisplay.cpp \
           daylabel.cpp \
           dayview.cpp \
           detailview.cpp \
           event.cpp \
           event_set.cpp \
           main.cpp \
           mainwindow.cpp \
           monthlabel.cpp \
           monthview.cpp \
           rotaryview.cpp \
           rotatablelabel.cpp \
           serialization.cpp \
           time1.cpp \
           time_t_read.cpp \
    saveeventwidget.cpp \
    selectablelabel.cpp \
    clickablelabel.cpp \
    calendarlistitem.cpp
RESOURCES += Resources.qrc

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
    android/res/values-id/strings.xml \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/res/drawable-hdpi/icon.png \
    android/res/values-it/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/values-id/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-de/strings.xml \
    android/res/drawable/icon.png \
    android/res/drawable/logo.png \
    android/res/values-ru/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-et/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/layout/splash.xml \
    android/version.xml \
    android/AndroidManifest.xml \
    android/res/values-es/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-ja/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values-el/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-fr/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-de/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-hdpi/icon.png \
    android/version.xml \
    android/AndroidManifest.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/res/values-es/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-ja/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values-el/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-fr/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-de/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-hdpi/icon.png \
    android/version.xml \
    android/AndroidManifest.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/res/values-es/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-ja/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values-el/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-fr/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-de/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-hdpi/icon.png \
    android/version.xml \
    android/AndroidManifest.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java
