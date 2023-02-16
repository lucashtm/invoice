add_executable(invoice
    main.cpp
    invoice_form.cpp
)

target_link_libraries(invoice PRIVATE Qt6::Widgets Qt6::PrintSupport)
