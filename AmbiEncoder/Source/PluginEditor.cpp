/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AmbiEncoderAudioProcessorEditor::AmbiEncoderAudioProcessorEditor (AmbiEncoderAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderPanPosition = new Slider ("new slider"));
    sliderPanPosition->setRange (0, 360, 0);
    sliderPanPosition->setSliderStyle (Slider::Rotary);
    sliderPanPosition->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderPanPosition->addListener (this);

    addAndMakeVisible (sliderHeightPosition = new Slider ("new slider"));
    sliderHeightPosition->setRange (0, 180, 0);
    sliderHeightPosition->setSliderStyle (Slider::Rotary);
    sliderHeightPosition->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sliderHeightPosition->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);//starts timer with interval of 200mS
    //[/Constructor]
}

AmbiEncoderAudioProcessorEditor::~AmbiEncoderAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderPanPosition = nullptr;
    sliderHeightPosition = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AmbiEncoderAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AmbiEncoderAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderPanPosition->setBounds (16, 16, 136, 120);
    sliderHeightPosition->setBounds (192, 16, 136, 120);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AmbiEncoderAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderPanPosition)
    {
        //[UserSliderCode_sliderPanPosition] -- add your slider handling code here..
        processor.panPosition = sliderPanPosition->getValue();
        //[/UserSliderCode_sliderPanPosition]
    }
    else if (sliderThatWasMoved == sliderHeightPosition)
    {
        //[UserSliderCode_sliderHeightPosition] -- add your slider handling code here..
        processor.heightPosition = sliderHeightPosition->getValue();
        //[/UserSliderCode_sliderHeightPosition]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AmbiEncoderAudioProcessorEditor::timerCallback()
{
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AmbiEncoderAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="AmbiEncoderAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="78c9cdbad904ed06" memberName="sliderPanPosition"
          virtualName="" explicitFocusOrder="0" pos="16 16 136 120" min="0"
          max="360" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="ee927b45a83ef515" memberName="sliderHeightPosition"
          virtualName="" explicitFocusOrder="0" pos="192 16 136 120" min="0"
          max="180" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
