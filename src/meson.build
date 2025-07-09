sources += files('main.cpp')

api_version = get_option('api_version')


if api_version == 1
    message('Using Foxbms1 api layer')

    subdir('foxbms1')
elif api_version == 2
    message('Using Foxbms2 api layer')

    subdir('foxbms2')
endif

subdir('dut')
