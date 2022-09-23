#pragma once
#include <GameEngineCore/GameEngineGUI.h>

class StageMain;
class HellperWindow : public GameEngineGUIWindow
{
public:
    HellperWindow();
    ~HellperWindow();

   HellperWindow(const HellperWindow& _Other)                = delete;
   HellperWindow(HellperWindow&& _Other) noexcept            = delete;
   HellperWindow& operator=(const HellperWindow& _Other)     = delete;
   HellperWindow& operator=(HellperWindow&& _Other) noexcept = delete;

   StageMain* m_MainSt;
protected:
    void Initialize(class GameEngineLevel* _Level) override;
    void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;

private:
 


    //void MetaFileButton();
    //void AtlasFileButton();

};
