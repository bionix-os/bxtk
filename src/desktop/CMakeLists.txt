target_sources(${PROJECT_NAME} PRIVATE
        window.h
        window.cpp
        popup.h
        popup.cpp
        popup_panel.h
        popup_panel.cpp
        popup_menu.h
        popup_menu.cpp
        accept_dialog.h
        accept_dialog.cpp
        confirmation_dialog.h
        confirmation_dialog.cpp
        file_dialog.h
        file_dialog.cpp
        status_indicator.h
        status_indicator.cpp
        bind_desktop_classes.h
        bind_desktop_classes.cpp
)

target_include_directories( ${PROJECT_NAME}
        PRIVATE
        "desktop"
)