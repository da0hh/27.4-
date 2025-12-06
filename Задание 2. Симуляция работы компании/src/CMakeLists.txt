add_executable ("practic_work" "main.cpp" "manager.cpp"  "worker.cpp" "ceo.cpp")

target_include_directories("practic_work" PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)