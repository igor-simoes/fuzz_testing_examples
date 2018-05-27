TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += *.h \
    book.h

SOURCES += booklibrary_target.cc \
    book.cc \
    main.cc
