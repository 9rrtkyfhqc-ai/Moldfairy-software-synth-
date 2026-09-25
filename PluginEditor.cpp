#define JUCE_FORCE_LEGACY_PARAMETER_AUTOMATION_TYPE 1

#include "JuceHeader.h"

#include "PluginProcessor.h"

#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), Moldfairy2 (p)
{
    //juce::ignoreUnused (Moldfairy2);
    imagefile = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob8.png");
    imagefile2 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob4.png");
    imagefile3 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob2.png");
    imagefile4 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob15.png");
    imagefile5 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("back.png");
    imagefile6 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob26.png");
    imagefile7 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob23.png");
    imagefile8 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob21.png");
    imagefile9 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob22.png");
    imagefile10 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob18.png");
    imagefile11 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob19.png");
    imagefile12 = file.getChildFile("Contents")
                    .getChildFile("Resources")
                    .getChildFile("images")
                    .getChildFile("knob20.png");

    if (imagefile7.existsAsFile()){
        knob6 = juce::ImageFileFormat::loadFrom(imagefile7);
    }
    if (imagefile5.existsAsFile()){
        back = juce::ImageFileFormat::loadFrom(imagefile5);
    }
    if (imagefile.existsAsFile()){
        knob = juce::ImageFileFormat::loadFrom(imagefile);
    }
    if (imagefile2.existsAsFile()){
        knob2 = juce::ImageFileFormat::loadFrom(imagefile2);
    }
    if (imagefile3.existsAsFile()){
        knob3 = juce::ImageFileFormat::loadFrom(imagefile3);
    }
    if (imagefile4.existsAsFile()){
        knob4 = juce::ImageFileFormat::loadFrom(imagefile4);
    }
    if (imagefile6.existsAsFile()){
        knob5 = juce::ImageFileFormat::loadFrom(imagefile6);
    }
    if (imagefile8.existsAsFile()){
        knob7 = juce::ImageFileFormat::loadFrom(imagefile8);
    }
    if (imagefile9.existsAsFile()){
        knob8 = juce::ImageFileFormat::loadFrom(imagefile9);
    }
    if (imagefile10.existsAsFile()){
        knob9 = juce::ImageFileFormat::loadFrom(imagefile10);
    }
    if (imagefile11.existsAsFile()){
        knob10 = juce::ImageFileFormat::loadFrom(imagefile11);
    }
    if (imagefile12.existsAsFile()){
        knob11 = juce::ImageFileFormat::loadFrom(imagefile12);
    }
    
    std::vector<std::pair<juce::String, juce::Slider*>> slidermap{
        {"VOL1", &slider1},
        {"VOL2", &slider2},
        {"VOL3", &slider3},
        {"VOL4", &slider4},

        {"FM1", &slider5},
        {"FM2", &slider6},
        {"FM3", &slider7},
        {"FM4", &slider8},

        {"CUTO", &slider9},
        {"RESO", &slider10},

        {"SHAP", &slider15},

        {"CUMO", &slider16},

        {"WAVE1", &slider17},
        {"WAVE2", &slider18},
        {"WAVE3", &slider19},
        {"WAVE4", &slider20},
        {"OCT1", &slider21},
        {"OCT2", &slider22},
        {"OCT3", &slider23},
        {"OCT4", &slider24},
        {"TONE1", &slider25},
        {"TONE2", &slider26},
        {"TONE3", &slider27},
        {"TONE4", &slider28},
        {"FINE1", &slider29},
        {"FINE2", &slider30},
        {"FINE3", &slider31},
        {"FINE4", &slider32},
        {"OS1N", &slider33},
        {"OS2N", &slider34},
        {"OS3N", &slider35},
        {"OS4N", &slider36},

        {"MOAP", &slider41},

        {"REMO", &slider42},

        {"VIV1", &slider43},
        {"VIV2", &slider44},
        {"VIV3", &slider45},
        {"VIV4", &slider46},

        {"VIS1", &slider47},

        {"OS1D", &slider49},
        {"OS2D", &slider50},
        {"OS3D", &slider51},
        {"OS4D", &slider52},

        {"DELA", &slider[1]},
        {"DELAF", &slider[2]},
        {"DELaL", &slider[3]},
        {"DELaR", &slider[4]},
        {"DELAFC", &slider[5]},
        

        {"REVEV", &slider[7]},
        {"REVEFC", &slider[8]},
        {"REVEH", &slider[9]},
        {"REVEL", &slider[10]}
    };

    std::vector<std::pair<juce::String, juce::Slider*>> slidermap2{
        {"FIAT", &slider11},
        {"FISU", &slider12},
        {"ATTA", &slider13},
        {"SUST", &slider14},

        {"FIDE", &slider37},
        {"FIRE", &slider38},
        {"DECA", &slider39},
        {"RELE", &slider40},
        
    };

    std::vector<std::pair<juce::String, juce::Slider*>> slidermap3{
        {"DELAFT", &slider[6]}
    };

    for (const auto& [paramID, sliderPtr] : slidermap){
        addAndMakeVisible(sliderPtr);
        sliderPtr->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        sliderPtr->setAlpha(0.0);
        sliderPtr->setSliderStyle (juce::Slider::RotaryVerticalDrag);
        sliderPtr->onValueChange = [this](){repaint();};
        attach.push_back(std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.STATES, paramID, *sliderPtr));
        sliders.push_back(sliderPtr);
    }

    for (const auto& [paramID, sliderPtr2] : slidermap2){
        addAndMakeVisible(sliderPtr2);
        sliderPtr2->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        sliderPtr2->setAlpha(0.0);
        sliderPtr2->setSliderStyle (juce::Slider::LinearBarVertical);
        sliderPtr2->onValueChange = [this](){repaint();};
        attach.push_back(std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.STATES, paramID, *sliderPtr2));
    }

    for (const auto& [paramID, sliderPtr3] : slidermap3){
        addAndMakeVisible(sliderPtr3);
        sliderPtr3->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        sliderPtr3->setAlpha(0.0);
        sliderPtr3->setSliderStyle (juce::Slider::LinearHorizontal);
        sliderPtr3->onValueChange = [this](){repaint();};
        attach.push_back(std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(p.STATES, paramID, *sliderPtr3));
    }

    setSize (840, 420);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    
     auto drawS = [&](const juce::Image& img, const juce::Slider& s, int X, int Y, int W, int H) 
    {
        auto b = s.getBounds();
        g.drawImage (img, b.getX(), b.getY(), b.getWidth(), b.getHeight(), 
                      X, Y, W, H, false);
    };

    auto draIndex = [&](juce::Slider& s, int F, int Px=1){
        float N = s.valueToProportionOfLength(s.getValue());
        int Ni = juce::jlimit(0, F, (int)(N * F))*Px;
        return Ni;
    };

    auto drawL = [&](juce::Slider& S,const juce::Image& im, int x=32, int y=-8, int sizX=20, int sizY=20, int nX=0, int Fy=0, int f=19, int p=20, int IsizX=20, int IsizY=20){
        auto Y = draIndex(S, f, p);
        auto b = S.getBounds();
        g.drawImage(im, b.getX()+x, b.getY()+y, sizX, sizY, nX, Y+Fy, IsizX, IsizY, false);
    };

    if (back.isValid()){
       g.drawImage(back, getLocalBounds().toFloat());
    }

    if (knob.isValid()){
       
        float num15 = slider15.valueToProportionOfLength(slider15.getValue());
        float num41 = slider41.valueToProportionOfLength(slider41.getValue());
    
        auto num15y2 = juce::jlimit(0, 19, (int)(num15 * 19))*20;
        auto num41y2 = juce::jlimit(0, 19, (int)(num41 * 19))*20;
        float num10 = slider10.valueToProportionOfLength(slider10.getValue());
        float num42 = slider42.valueToProportionOfLength(slider42.getValue());

        if (knob5.isValid()){
            g.drawImage(knob5, slider[3].getBounds().getX(),  slider[3].getBounds().getY()+42, 120, 8, 0, 320+(int)(slider[3].getValue()-1)*20, 300, 20, false);
            g.drawImage(knob5, slider[3].getBounds().getX(),  slider[3].getBounds().getY()+52, 120, 8, 0, (int)(slider[4].getValue()-1)*20, 300, 20, false);
        }

        if (knob7.isValid()){
            auto num10y2 = juce::jlimit(0, 19, (int)(num10 * 19))*20;
            g.drawImage(knob7, slider10.getBounds().getX()+42, slider10.getBounds().getY()-10, 22, 22, 0, num10y2, 20, 20, false);
            auto num42y2 = juce::jlimit(0, 19, (int)(num42 * 19))*20; 
            g.drawImage(knob7, slider42.getBounds().getX()+32, slider42.getBounds().getY()-5, 16, 16, 0, num42y2, 20, 20, false);
            drawL(slider[2], knob7, 26, -14);
            drawL(slider[8], knob7, 32, -10);
        }

        if (knob8.isValid()){
           
            float num5 = slider5.valueToProportionOfLength(slider5.getValue());
            float num6 = slider6.valueToProportionOfLength(slider6.getValue());
            float num7 = slider7.valueToProportionOfLength(slider7.getValue());
            float num8 = slider8.valueToProportionOfLength(slider8.getValue());
      
            auto num5y2 = juce::jlimit(0, 19, (int)(num5 * 19))*20;
            auto num6y2 = juce::jlimit(0, 19, (int)(num6 * 19))*20;
            auto num7y2 = juce::jlimit(0, 19, (int)(num7 * 19))*20;
            auto num8y2 = juce::jlimit(0, 19, (int)(num8 * 19))*20;

            

            g.drawImage(knob8, slider5.getBounds().getX()+42, slider5.getBounds().getY()-10, 22, 22, 0, num5y2, 20, 20, false);
            g.drawImage(knob8, slider6.getBounds().getX()+42, slider6.getBounds().getY()-10, 22, 22, 0, num6y2, 20, 20, false);
            g.drawImage(knob8, slider7.getBounds().getX()+42, slider7.getBounds().getY()-10, 22, 22, 0, num7y2, 20, 20, false);
            g.drawImage(knob8, slider8.getBounds().getX()+42, slider8.getBounds().getY()-10, 22, 22, 0, num8y2, 20, 20, false);

            g.drawImage(knob8, slider15.getBounds().getX()-11, slider15.getBounds().getY()-8, 20, 20, 0, 380-num15y2, 20, 20, false);
            g.drawImage(knob8, slider41.getBounds().getX()-11, slider41.getBounds().getY()-4, 20, 20, 0, 380-num41y2, 20, 20, false);

            drawL(slider49, knob8, 28, -4, 18, 18);
            drawL(slider50, knob8, 28, -4, 18, 18);
            drawL(slider51, knob8, 28, -4, 18, 18);
            drawL(slider52, knob8, 28, -4, 18, 18);

            drawL(slider[3], knob8, 10, -15);
            drawL(slider[10], knob8, 10, -16, 16, 16);
        }
        
        if (knob9.isValid()){
             float num1 = slider1.valueToProportionOfLength(slider1.getValue());
             float num2 = slider2.valueToProportionOfLength(slider2.getValue());
             float num3 = slider3.valueToProportionOfLength(slider3.getValue());
             float num4 = slider4.valueToProportionOfLength(slider4.getValue());
       
            auto num1y2 = juce::jlimit(0, 19, (int)(num1 * 19))*20;
            auto num2y2 = juce::jlimit(0, 19, (int)(num2 * 19))*20;
            auto num3y2 = juce::jlimit(0, 19, (int)(num3 * 19))*20;
            auto num4y2 = juce::jlimit(0, 19, (int)(num4 * 19))*20;
            
            g.drawImage(knob9, 62, 10, 26, 26, 0, num1y2, 20, 20, false);
            g.drawImage(knob9, 142, 10, 26, 26, 0, num2y2, 20, 20, false);
            g.drawImage(knob9, 222, 10, 26, 26, 0, num3y2, 20, 20, false);
            g.drawImage(knob9, 302, 10, 26, 26, 0, num4y2, 20, 20, false);

            drawL(slider[1], knob9, 26, -14);
            drawL(slider[7], knob9, 32, -10);
        }
        if (knob10.isValid()){
            float num9 = slider9.valueToProportionOfLength(slider9.getValue());
            float num16 = slider16.valueToProportionOfLength(slider16.getValue());
           
            auto num16y2 = juce::jlimit(0, 19, (int)(num16 * 19))*20;
            auto num9y2 = juce::jlimit(0, 19, (int)(num9 * 19))*20;
            g.drawImage(knob10, slider9.getBounds().getX()+42, slider9.getBounds().getY()-8, 22, 22, 0, num9y2, 20, 20, false);  
            g.drawImage(knob10, slider16.getBounds().getX()+32, slider16.getBounds().getY()-8, 18, 18, 0, num16y2, 20, 20, false);
            g.drawImage(knob10, slider15.getBounds().getX()+30, slider15.getBounds().getY()-6, 18, 18, 0, num15y2, 20, 20, false);
            g.drawImage(knob10, slider41.getBounds().getX()+28, slider41.getBounds().getY()-4, 18, 18, 0, num41y2, 20, 20, false);

            drawL(slider43, knob10);
            drawL(slider44, knob10);
            drawL(slider45, knob10);
            drawL(slider46, knob10);

            drawL(slider[4], knob10, 10, -15);
            drawL(slider[5], knob10, 12, -16, 16, 16);
            drawL(slider[9], knob10, 9, -16, 16, 16);
        }
    }
    if (knob11.isValid()){

        float num11 = slider11.valueToProportionOfLength(slider11.getValue());
        auto num11y = juce::jlimit(0, 19, (int)(num11 * 19));
        g.drawImage(knob11, slider11.getBounds().getX(), slider11.getBounds().getY(), slider11.getBounds().getWidth(), slider11.getBounds().getHeight(), 0, 1140-num11y*60, 24, 60, false);

        float num12 = slider12.valueToProportionOfLength(slider12.getValue());
        auto num12y = juce::jlimit(0, 19, (int)(num12 * 19));
        g.drawImage(knob11, slider12.getBounds().getX(), slider12.getBounds().getY(), slider12.getBounds().getWidth(), slider12.getBounds().getHeight(), 0, 1140-num12y*60, 24, 60, false);

        float num13 = slider13.valueToProportionOfLength(slider13.getValue());
        auto num13y = juce::jlimit(0, 19, (int)(num13 * 19));
        g.drawImage(knob11, slider13.getBounds().getX(), slider13.getBounds().getY(), slider13.getBounds().getWidth(), slider13.getBounds().getHeight(), 0, 1140-num13y*60, 24, 60, false);

        float num14 = slider14.valueToProportionOfLength(slider14.getValue());
        auto num14y = juce::jlimit(0, 19, (int)(num14 * 19));
        g.drawImage(knob11, slider14.getBounds().getX(), slider14.getBounds().getY(), slider14.getBounds().getWidth(), slider14.getBounds().getHeight(), 0, 1140-num14y*60, 24, 60, false);

        float num37 = slider37.valueToProportionOfLength(slider37.getValue());
        float num38 = slider38.valueToProportionOfLength(slider38.getValue());
        float num39 = slider39.valueToProportionOfLength(slider39.getValue());
        float num40 = slider40.valueToProportionOfLength(slider40.getValue());

        auto num37y = juce::jlimit(0, 19, (int)(num37 * 19));
        auto num38y = juce::jlimit(0, 19, (int)(num38 * 19));
        auto num39y = juce::jlimit(0, 19, (int)(num39 * 19));
        auto num40y = juce::jlimit(0, 19, (int)(num40 * 19));    

        drawS(knob11, slider37, 0, 1140-num37y*60, 24, 60);
        drawS(knob11, slider38, 0, 1140-num38y*60, 24, 60);
        drawS(knob11, slider39, 0, 1140-num39y*60, 24, 60);
        drawS(knob11, slider40, 0, 1140-num40y*60, 24, 60);
        
    }
    if (knob6.isValid()){
        drawS(knob6, slider[6], draIndex(slider[6], 19, 60), 0, 60, 24);
    }
    if (knob4.isValid()){
        for (const auto& s : sliders){
            auto b = s->getBounds();
            float num = s->valueToProportionOfLength(s->getValue());
            auto f = juce::jlimit(0, 100, (int)(num * 100));
            int y = 60*((f+4) % 6);
            int x = 60*((f+4) / 6);
            g.drawImage(knob4, b.getX(), b.getY(), b.getWidth(), b.getHeight(), x, y, 60, 60, false);
        }
    }
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    slider1.setBounds(30, 30, 60, 60);
    slider2.setBounds(110, 30, 60, 60);
    slider3.setBounds(190, 30, 60, 60);
    slider4.setBounds(270, 30, 60, 60);

    slider5.setBounds(365, 40, 50, 50);
    slider6.setBounds(445, 40, 50, 50);
    slider7.setBounds(525, 40, 50, 50);
    slider8.setBounds(605, 40, 50, 50);
    slider9.setBounds(685, 40, 60, 60);
    slider10.setBounds(765, 40, 60, 60);

    slider11.setBounds(365, 110, 20, 100);
    slider12.setBounds(445, 110, 20, 100);
    slider13.setBounds(525, 110, 20, 100);
    slider14.setBounds(605, 110, 20, 100);
    slider15.setBounds(698, 122, 38, 38);
    slider16.setBounds(760, 114, 40, 40);

    //==Wave
    slider17.setBounds(42, 100, 35, 35);
    slider18.setBounds(122, 100, 35, 35);
    slider19.setBounds(202, 100, 35, 35);
    slider20.setBounds(282, 100, 35, 35);
    //==Oct
    slider21.setBounds(36, 140, 25, 25);
    slider22.setBounds(116, 140, 25, 25);
    slider23.setBounds(197, 140, 25, 25);
    slider24.setBounds(277, 140, 25, 25);
    //==Tone
    slider25.setBounds(52, 170, 25, 25);
    slider26.setBounds(132, 170, 25, 25);
    slider27.setBounds(213, 170, 25, 25);
    slider28.setBounds(293, 170, 25, 25);
    //==Fine
    slider29.setBounds(42, 200, 25, 25);
    slider30.setBounds(122, 200, 25, 25);
    slider31.setBounds(203, 200, 25, 25);
    slider32.setBounds(283, 200, 25, 25);
    //==Uni
    slider33.setBounds(62, 237, 35, 35);
    slider34.setBounds(142, 237, 35, 35);
    slider35.setBounds(223, 237, 35, 35);
    slider36.setBounds(303, 237, 35, 35);

    slider37.setBounds(405, 110, 20, 100);
    slider38.setBounds(485, 110, 20, 100);
    slider39.setBounds(565, 110, 20, 100);
    slider40.setBounds(645, 110, 20, 100);
    slider41.setBounds(722, 172, 34, 34);
    slider42.setBounds(782, 166, 36, 36);

    slider43.setBounds(370, 230, 40, 40);
    slider44.setBounds(450, 230, 40, 40);
    slider45.setBounds(530, 230, 40, 40);
    slider46.setBounds(610, 230, 40, 40);
    slider47.setBounds(683, 226, 50, 50);

    //==Detune
    slider49.setBounds(32, 280, 35, 35);
    slider50.setBounds(112, 280, 35, 35);
    slider51.setBounds(193, 280, 35, 35);
    slider52.setBounds(273, 280, 35, 35);

    //==delay
    slider[3].setBounds(345, 290, 38, 38);
    slider[4].setBounds(425, 290, 38, 38);
    slider[2].setBounds(486, 336, 38, 38);
    slider[1].setBounds(566, 336, 38, 38);
    slider[5].setBounds(529, 292, 34, 34);
    slider[6].setBounds(375, 352, 60, 24);

    //==Reverb
    slider[9].setBounds(674, 354, 36, 36);
    slider[10].setBounds(636, 313, 36, 36);
    slider[7].setBounds(745, 353, 40, 40);
    slider[8].setBounds(705, 308, 40, 40);
}