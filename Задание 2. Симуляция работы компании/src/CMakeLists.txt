add_executable ("practic_work" "main.cpp"  "manager.cpp" "ceo.cpp" "employee.cpp")

target_include_directories("practic_work" PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)