cmake_minimum_required(VERSION 3.25)

project(XYApp VERSION 1.0 LANGUAGES CXX)

# ============================================================
# C++ 标准
# ============================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# Qt 自动处理
# ============================================================
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(HEADERS
    src/include/config_manager.h
    src/include/logger.h
    src/ui/mainwindow.h
    src/ui/leftpanel.h
)

set(SOURCES
    src/main.cpp
    src/config_manager.cpp
    src/logger.cpp
    src/ui/mainwindow.cpp
    src/ui/leftpanel.cpp
)

set(QtUI
#    ui/mainwindow.ui
    src/ui/left.ui
#   src/ui/right.ui
)

# ============================================================
# Qt 查找（关键）
# ============================================================
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Network
)
find_package(spdlog CONFIG REQUIRED)
# ============================================================
# 可执行文件
# ============================================================
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${QtUI}
)

# ============================================================
# 链接 Qt
# ============================================================
target_link_libraries(XYApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    spdlog::spdlog
)

target_include_directories(XYApp PRIVATE
    BEFORE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include"          # your own headers
)


# ============================================================
# Windows 优化
# ============================================================
if(MSVC)
    target_compile_options(XYApp PRIVATE /W4 /utf-8)
endif()

# ============================================================
# windeployqt（可选）
# ============================================================
if(WIN32)
    find_program(WINDEPLOYQT windeployqt)

    if(WINDEPLOYQT)
        add_custom_target(deploy
            COMMAND ${WINDEPLOYQT} $<TARGET_FILE:XYApp>
            DEPENDS XYApp
        )
    endif()
endif()

