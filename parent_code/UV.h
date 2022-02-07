#ifndef UV_h
#define UV_h

#include "Constants.h"


class UV
{
  public:
    
    UV();
    Constants constants;
    void updateUVStat();
    String putStatusToSDCard();
    String putStatusToSDCard1();
    int reset();
    void statusOfUV();
    bool chooseButtonPressed(int buttonToBePressed);
    String errorStatusToDisplay(long currentEpooch);

    bool muteStatus(long lightIdentifierValue, int lightNum, long currentEpooch);

    long ledHoursRun1 = 0;
    long ledHoursRun2 = 0;
    long ledHoursRun3 = 0;
    long ledHoursRun4 = 0;
    long ledHoursRun5 = 0;
    long ledHoursRun6 = 0;
    long ledHoursRun7 = 0;
    long ledHoursRun8 = 0;
    long ledHoursRun9 = 0;
    long ledHoursRun10 = 0;
    long ledHoursRun11 = 0;
    long ledHoursRun12 = 0;
    long ledHoursRun13 = 0;
    long ledHoursRun14 = 0;
    long ledHoursRun15 = 0;
    long ledHoursRun16 = 0;
    long ledHoursRun17 = 0;
    long ledHoursRun18 = 0;
    long ledHoursRun19 = 0;
    long ledHoursRun20 = 0;
    long ledHoursRun21 = 0;
    long ledHoursRun22 = 0;
    long ledHoursRun23 = 0;
    long ledHoursRun24 = 0;
    long ledHoursRun25 = 0;
    long ledHoursRun26 = 0;
    long ledHoursRun27 = 0;
    long ledHoursRun28 = 0;
    long ledHoursRun29 = 0;
    long ledHoursRun30 = 0;
    long ledHoursRun31 = 0;
    long ledHoursRun32 = 0;
    long ledHoursRun33 = 0;
    long ledHoursRun34 = 0;
    long ledHoursRun35 = 0;
    long ledHoursRun36 = 0;
    long ledHoursRun37 = 0;
    long ledHoursRun38 = 0;
    long ledHoursRun39 = 0;
    long ledHoursRun40 = 0;
    long ledHoursRun41 = 0;
    long ledHoursRun42 = 0;
    long ledHoursRun43 = 0;
    long ledHoursRun44 = 0;
    long ledHoursRun45 = 0;
    long ledHoursRun46 = 0;
    long ledHoursRun47 = 0;
    long ledHoursRun48 = 0;
    long ledHoursRun49 = 0;
    long ledHoursRun50 = 0;
    long ledHoursRun51 = 0;
    long ledHoursRun52 = 0;
    long ledHoursRun53 = 0;
    long ledHoursRun54 = 0;
    long ledHoursRun55 = 0;
    long ledHoursRun56 = 0;
    long ledHoursRun57 = 0;
    long ledHoursRun58 = 0;
    long ledHoursRun59 = 0;
    long ledHoursRun60 = 0;
    
    long ledlastBuzzed1 = 0;
    long ledlastBuzzed2 = 0;
    long ledlastBuzzed3 = 0;
    long ledlastBuzzed4 = 0;
    long ledlastBuzzed5 = 0;
    long ledlastBuzzed6 = 0;
    long ledlastBuzzed7 = 0;
    long ledlastBuzzed8 = 0;
    long ledlastBuzzed9 = 0;
    long ledlastBuzzed10 = 0;
    long ledlastBuzzed11 = 0;
    long ledlastBuzzed12 = 0;
    long ledlastBuzzed13 = 0;
    long ledlastBuzzed14 = 0;
    long ledlastBuzzed15 = 0;
    long ledlastBuzzed16 = 0;
    long ledlastBuzzed17 = 0;
    long ledlastBuzzed18 = 0;
    long ledlastBuzzed19 = 0;
    long ledlastBuzzed20 = 0;
    long ledlastBuzzed21 = 0;
    long ledlastBuzzed22 = 0;
    long ledlastBuzzed23 = 0;
    long ledlastBuzzed24 = 0;
    long ledlastBuzzed25 = 0;
    long ledlastBuzzed26 = 0;
    long ledlastBuzzed27 = 0;
    long ledlastBuzzed28 = 0;
    long ledlastBuzzed29 = 0;
    long ledlastBuzzed30 = 0;
    long ledlastBuzzed31 = 0;
    long ledlastBuzzed32 = 0;
    long ledlastBuzzed33 = 0;
    long ledlastBuzzed34 = 0;
    long ledlastBuzzed35 = 0;
    long ledlastBuzzed36 = 0;
    long ledlastBuzzed37 = 0;
    long ledlastBuzzed38 = 0;
    long ledlastBuzzed39 = 0;
    long ledlastBuzzed40 = 0;
    long ledlastBuzzed41 = 0;
    long ledlastBuzzed42 = 0;
    long ledlastBuzzed43 = 0;
    long ledlastBuzzed44 = 0;
    long ledlastBuzzed45 = 0;
    long ledlastBuzzed46 = 0;
    long ledlastBuzzed47 = 0;
    long ledlastBuzzed48 = 0;
    long ledlastBuzzed49 = 0;
    long ledlastBuzzed50 = 0;
    long ledlastBuzzed51 = 0;
    long ledlastBuzzed52 = 0;
    long ledlastBuzzed53 = 0;
    long ledlastBuzzed54 = 0;
    long ledlastBuzzed55 = 0;
    long ledlastBuzzed56 = 0;
    long ledlastBuzzed57 = 0;
    long ledlastBuzzed58 = 0;
    long ledlastBuzzed59 = 0;
    long ledlastBuzzed60 = 0;
  
    int erroredLight[60] = {0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 
                            0, 0, 0, 0};

    byte led1Status = '0';
    byte led2Status = '0';
    byte led3Status = '0';
    byte led4Status = '0';
    byte led5Status = '0';
    byte led6Status = '0';
    byte led7Status = '0';
    byte led8Status = '0';
    byte led9Status = '0';
    byte led10Status = '0';
    byte led11Status = '0';
    byte led12Status = '0';
    byte led13Status = '0';
    byte led14Status = '0';
    byte led15Status = '0';
    byte led16Status = '0';
    byte led17Status = '0';
    byte led18Status = '0';
    byte led19Status = '0';
    byte led20Status = '0';
    byte led21Status = '0';
    byte led22Status = '0';
    byte led23Status = '0';
    byte led24Status = '0';
    byte led25Status = '0';
    byte led26Status = '0';
    byte led27Status = '0';
    byte led28Status = '0';
    byte led29Status = '0';
    byte led30Status = '0';
    byte led31Status = '0';
    byte led32Status = '0';
    byte led33Status = '0';
    byte led34Status = '0';
    byte led35Status = '0';
    byte led36Status = '0';
    byte led37Status = '0';
    byte led38Status = '0';
    byte led39Status = '0';
    byte led40Status = '0';
    byte led41Status = '0';
    byte led42Status = '0';
    byte led43Status = '0';
    byte led44Status = '0';
    byte led45Status = '0';
    byte led46Status = '0';
    byte led47Status = '0';
    byte led48Status = '0';
    byte led49Status = '0';
    byte led50Status = '0';
    byte led51Status = '0';
    byte led52Status = '0';
    byte led53Status = '0';
    byte led54Status = '0';
    byte led55Status = '0';
    byte led56Status = '0';
    byte led57Status = '0';
    byte led58Status = '0';
    byte led59Status = '0';
    byte led60Status = '0';
    
    String buttonPressedData;
    String lightData;

    long defaultLightHours = 9000;
    long defaultBuzzerHours = 48;
    long calculatedBuzzerHours = defaultBuzzerHours * 60;
    long calculatedLightHours = defaultLightHours * 60;

};
#endif
