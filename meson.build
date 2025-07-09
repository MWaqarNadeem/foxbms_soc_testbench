project('Foxbms SOX unittest', ['c', 'cpp'], default_options: {'cpp_std': 'c++20', 'warning_level': '3'})

sources = []
subdir('src')

executable('basic_test', sources, include_directories: [api_include])
