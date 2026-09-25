cmake_minimum_required(VERSION 3.22)

if (APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "Build architectures for macOS" FORCE)
endif()

project(Moldfairy2 VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(JUCE)

juce_add_plugin(Moldfairy2
    PLUGIN_MANUFACTURER_CODE Fair
    PLUGIN_CODE Fair             
    FORMATS AU Standalone VST3
    PRODUCT_NAME "Moldfairy2"
    COMPANY_NAME "Nitratech"
    BUNDLE_ID "com.nitratech.moldfairy2" 
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_WEB_BROWSER FALSE
    NEEDS_CURL FALSE
)

juce_generate_juce_header(Moldfairy2)

set_target_properties(Moldfairy2 PROPERTIES
    C_VISIBILITY_PRESET hidden
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

target_sources(Moldfairy2 PRIVATE
    PluginEditor.cpp
    PluginEditor.h
    PluginProcessor.cpp
    PluginProcessor.h
)

set(PLUGIN_FORMAT_TARGETS
    "Moldfairy2_AU"
    "Moldfairy2_VST3"
    "Moldfairy2_Standalone"
)

foreach(format_target IN LISTS PLUGIN_FORMAT_TARGETS)
    if(TARGET ${format_target})
        juce_add_bundle_resources_directory(${format_target} "${CMAKE_CURRENT_SOURCE_DIR}/images")
    endif()
endforeach()


target_compile_definitions(Moldfairy2 PRIVATE
    JUCE_FORCE_USE_LEGACY_PARAM_IDS=1
    JUCE_WEB_BROWSER=0 
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(Moldfairy2 PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_audio_formats
    juce::juce_audio_plugin_client
    juce::juce_audio_processors
    juce::juce_core
    juce::juce_data_structures
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
    juce::juce_midi_ci
)
