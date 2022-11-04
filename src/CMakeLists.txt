add_executable(helloworld
    main.cpp
    invoice_form.cpp
)

target_link_libraries(helloworld PRIVATE Qt6::Widgets)
