cmake_minimum_required(VERSION 3.19)
project(laba25 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(laba25
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    cardform.ui
    cardform.h
    r.h
    rup.h
    amp.h
    date.h
    cardform.cpp
    rup.cpp
    amp.cpp
)

target_link_libraries(laba25
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS laba25
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET laba25
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
