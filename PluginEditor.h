#define JUCE_FORCE_LEGACY_PARAMETER_AUTOMATION_TYPE 1

#pragma once

#include "JuceHeader.h"

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    juce::File file = juce::File::getSpecialLocation(juce::File::SpecialLocationType::currentApplicationFile);
    juce::File imagefile;
    juce::File imagefile2;
    juce::File imagefile3;
    juce::File imagefile4;
    juce::File imagefile5;
    juce::File imagefile6;
    juce::File imagefile7;
    juce::File imagefile8;
    juce::File imagefile9;
    juce::File imagefile10;
    juce::File imagefile11;
    juce::File imagefile12;

    juce::Image back;
    juce::Image knob;
    juce::Image knob2;
    juce::Image knob3;
    juce::Image knob4;
    juce::Image knob5;
    juce::Image knob6;
    juce::Image knob7;
    juce::Image knob8;
    juce::Image knob9;
    juce::Image knob10;
    juce::Image knob11;

    std::array<juce::Slider, 12> slider;
    std::vector<juce::Slider*> sliders;

    juce::Slider slider1, slider2, slider3, slider4, slider5, slider6, slider7, slider8, slider9, slider10, slider11, slider12, slider13, slider14, slider15, slider16, slider17, slider18, slider19, slider20, slider21, slider22, slider23, slider24, slider25, slider26, slider27, slider28, slider29, slider30;
    juce::Slider slider31, slider32, slider33, slider34, slider35, slider36, slider37, slider38, slider39, slider40, slider41, slider42, slider43, slider44, slider45, slider46, slider47, slider49, slider50, slider51, slider52, slider53, slider54;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>> attach;

    static inline const int animationIndex[]{
        120,
        160,
        200,
        240,
        280,
        320,
        360,
        400,
        440,
        480,
        520,
        560,
        600,
        640,
        680,
        720,
        760,
        0
    };
    
    static inline const int animationIndex2[]{
        0,
        440,
        40,
        480,
        80,
        520,
        120,
        560,
        160,
        600,
        200,
        640,
        240,
        680,
        280,
        720,
        320,
        760
    };
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& Moldfairy2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
