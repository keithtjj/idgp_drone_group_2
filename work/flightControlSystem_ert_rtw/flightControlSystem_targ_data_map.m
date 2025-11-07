    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 22;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (flightControlSystem_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.Sensors
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.Constant_Value
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.switch_way_Threshold
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.DataStoreMemory_InitialValue
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.RateTransition_InitialCondition
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.outlierBelowFloor_const
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.outlierJump_const
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.currentEstimateVeryOffFromPressure_const
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.currentStateVeryOffsonarflt_const
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.Checkerrorcondition_const
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_P.ControlSystem.u0continuousOFerrors_const
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 40;
            section.data(40)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_D
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_I
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.Velocitycontroller_I
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 4;

                    ;% flightControlSystem_P.ControlSystem.DiscreteDerivative_ICPrevScaledInput
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 5;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_InitialConditionForFilter
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 6;

                    ;% flightControlSystem_P.ControlSystem.Velocitycontroller_InitialConditionForIntegrator
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 7;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_InitialConditionForIntegrator
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 8;

                    ;% flightControlSystem_P.ControlSystem.Positioncontroller_LowerSaturationLimit
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 9;

                    ;% flightControlSystem_P.ControlSystem.Velocitycontroller_LowerSaturationLimit
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 10;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_LowerSaturationLimit
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 11;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_N
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 12;

                    ;% flightControlSystem_P.ControlSystem.Positioncontroller_P
                    section.data(12).logicalSrcIdx = 23;
                    section.data(12).dtTransOffset = 14;

                    ;% flightControlSystem_P.ControlSystem.Velocitycontroller_P
                    section.data(13).logicalSrcIdx = 24;
                    section.data(13).dtTransOffset = 15;

                    ;% flightControlSystem_P.ControlSystem.Anglecontrolloop_P
                    section.data(14).logicalSrcIdx = 25;
                    section.data(14).dtTransOffset = 16;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_P
                    section.data(15).logicalSrcIdx = 26;
                    section.data(15).dtTransOffset = 17;

                    ;% flightControlSystem_P.ControlSystem.Positioncontroller_UpperSaturationLimit
                    section.data(16).logicalSrcIdx = 27;
                    section.data(16).dtTransOffset = 19;

                    ;% flightControlSystem_P.ControlSystem.Velocitycontroller_UpperSaturationLimit
                    section.data(17).logicalSrcIdx = 28;
                    section.data(17).dtTransOffset = 20;

                    ;% flightControlSystem_P.ControlSystem.Angularvelocitycontrolloop_UpperSaturationLimit
                    section.data(18).logicalSrcIdx = 29;
                    section.data(18).dtTransOffset = 21;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant_const
                    section.data(19).logicalSrcIdx = 30;
                    section.data(19).dtTransOffset = 22;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant1_const
                    section.data(20).logicalSrcIdx = 31;
                    section.data(20).dtTransOffset = 23;

                    ;% flightControlSystem_P.ControlSystem.maxp_const
                    section.data(21).logicalSrcIdx = 32;
                    section.data(21).dtTransOffset = 24;

                    ;% flightControlSystem_P.ControlSystem.maxq_const
                    section.data(22).logicalSrcIdx = 33;
                    section.data(22).dtTransOffset = 25;

                    ;% flightControlSystem_P.ControlSystem.maxw1_const
                    section.data(23).logicalSrcIdx = 34;
                    section.data(23).dtTransOffset = 26;

                    ;% flightControlSystem_P.ControlSystem.maxw2_const
                    section.data(24).logicalSrcIdx = 35;
                    section.data(24).dtTransOffset = 27;

                    ;% flightControlSystem_P.ControlSystem.maxdw1_const
                    section.data(25).logicalSrcIdx = 36;
                    section.data(25).dtTransOffset = 28;

                    ;% flightControlSystem_P.ControlSystem.maxdw2_const
                    section.data(26).logicalSrcIdx = 37;
                    section.data(26).dtTransOffset = 29;

                    ;% flightControlSystem_P.ControlSystem.maxp2_const
                    section.data(27).logicalSrcIdx = 38;
                    section.data(27).dtTransOffset = 30;

                    ;% flightControlSystem_P.ControlSystem.maxq2_const
                    section.data(28).logicalSrcIdx = 39;
                    section.data(28).dtTransOffset = 31;

                    ;% flightControlSystem_P.ControlSystem.maxw3_const
                    section.data(29).logicalSrcIdx = 40;
                    section.data(29).dtTransOffset = 32;

                    ;% flightControlSystem_P.ControlSystem.maxw4_const
                    section.data(30).logicalSrcIdx = 41;
                    section.data(30).dtTransOffset = 33;

                    ;% flightControlSystem_P.ControlSystem.minHeightforOF_const
                    section.data(31).logicalSrcIdx = 42;
                    section.data(31).dtTransOffset = 34;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_j
                    section.data(32).logicalSrcIdx = 43;
                    section.data(32).dtTransOffset = 35;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant1_const_e
                    section.data(33).logicalSrcIdx = 44;
                    section.data(33).dtTransOffset = 36;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant2_const
                    section.data(34).logicalSrcIdx = 45;
                    section.data(34).dtTransOffset = 37;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant3_const
                    section.data(35).logicalSrcIdx = 46;
                    section.data(35).dtTransOffset = 38;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant4_const
                    section.data(36).logicalSrcIdx = 47;
                    section.data(36).dtTransOffset = 39;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant5_const
                    section.data(37).logicalSrcIdx = 48;
                    section.data(37).dtTransOffset = 40;

                    ;% flightControlSystem_P.ControlSystem.DeactivateAccelerationIfOFisnotusedduetolowaltitude_const
                    section.data(38).logicalSrcIdx = 49;
                    section.data(38).dtTransOffset = 41;

                    ;% flightControlSystem_P.ControlSystem.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto200_con
                    section.data(39).logicalSrcIdx = 50;
                    section.data(39).dtTransOffset = 42;

                    ;% flightControlSystem_P.ControlSystem.donotuseaccifopticalflowneveravailableNoteOF60HzbutZOHto2001_co
                    section.data(40).logicalSrcIdx = 51;
                    section.data(40).dtTransOffset = 43;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold
                    section.data(1).logicalSrcIdx = 52;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold_e
                    section.data(2).logicalSrcIdx = 53;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold_k
                    section.data(3).logicalSrcIdx = 54;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_h
                    section.data(4).logicalSrcIdx = 55;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_l
                    section.data(5).logicalSrcIdx = 56;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.WrapToZero_Threshold_c
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.CompareToConstant_const_c
                    section.data(2).logicalSrcIdx = 58;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem._Value
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.Lykyhatkk1_Y0
                    section.data(2).logicalSrcIdx = 60;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.deltax_Y0
                    section.data(3).logicalSrcIdx = 61;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value
                    section.data(4).logicalSrcIdx = 62;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainM_Value
                    section.data(5).logicalSrcIdx = 63;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_P.ControlSystem.C_Value
                    section.data(6).logicalSrcIdx = 64;
                    section.data(6).dtTransOffset = 6;

                    ;% flightControlSystem_P.ControlSystem.Delay2_InitialCondition
                    section.data(7).logicalSrcIdx = 65;
                    section.data(7).dtTransOffset = 8;

                    ;% flightControlSystem_P.ControlSystem.X0_Value
                    section.data(8).logicalSrcIdx = 66;
                    section.data(8).dtTransOffset = 9;

                    ;% flightControlSystem_P.ControlSystem.SaturationSonar_LowerSat
                    section.data(9).logicalSrcIdx = 67;
                    section.data(9).dtTransOffset = 11;

                    ;% flightControlSystem_P.ControlSystem.sonarFilter_IIR_NumCoef
                    section.data(10).logicalSrcIdx = 68;
                    section.data(10).dtTransOffset = 12;

                    ;% flightControlSystem_P.ControlSystem.sonarFilter_IIR_DenCoef
                    section.data(11).logicalSrcIdx = 69;
                    section.data(11).dtTransOffset = 16;

                    ;% flightControlSystem_P.ControlSystem.sonarFilter_IIR_InitialStates
                    section.data(12).logicalSrcIdx = 70;
                    section.data(12).dtTransOffset = 20;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainM_Value_l
                    section.data(13).logicalSrcIdx = 71;
                    section.data(13).dtTransOffset = 21;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainM_Value_a
                    section.data(14).logicalSrcIdx = 72;
                    section.data(14).dtTransOffset = 23;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainM_Value_i
                    section.data(15).logicalSrcIdx = 73;
                    section.data(15).dtTransOffset = 25;

                    ;% flightControlSystem_P.ControlSystem.speed_Value
                    section.data(16).logicalSrcIdx = 74;
                    section.data(16).dtTransOffset = 33;

                    ;% flightControlSystem_P.ControlSystem.Wait3Seconds_Value
                    section.data(17).logicalSrcIdx = 75;
                    section.data(17).dtTransOffset = 34;

                    ;% flightControlSystem_P.ControlSystem.DelayOneStep_InitialCondition
                    section.data(18).logicalSrcIdx = 76;
                    section.data(18).dtTransOffset = 35;

                    ;% flightControlSystem_P.ControlSystem.u5meters_Value
                    section.data(19).logicalSrcIdx = 77;
                    section.data(19).dtTransOffset = 36;

                    ;% flightControlSystem_P.ControlSystem.A_Value
                    section.data(20).logicalSrcIdx = 78;
                    section.data(20).dtTransOffset = 37;

                    ;% flightControlSystem_P.ControlSystem.B_Value
                    section.data(21).logicalSrcIdx = 79;
                    section.data(21).dtTransOffset = 41;

                    ;% flightControlSystem_P.ControlSystem.CovarianceZ_Value
                    section.data(22).logicalSrcIdx = 80;
                    section.data(22).dtTransOffset = 43;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainL_Value
                    section.data(23).logicalSrcIdx = 81;
                    section.data(23).dtTransOffset = 47;

                    ;% flightControlSystem_P.ControlSystem.D_Value
                    section.data(24).logicalSrcIdx = 82;
                    section.data(24).dtTransOffset = 49;

                    ;% flightControlSystem_P.ControlSystem.P0_Value
                    section.data(25).logicalSrcIdx = 83;
                    section.data(25).dtTransOffset = 50;

                    ;% flightControlSystem_P.ControlSystem.G_Value
                    section.data(26).logicalSrcIdx = 84;
                    section.data(26).dtTransOffset = 54;

                    ;% flightControlSystem_P.ControlSystem.H_Value
                    section.data(27).logicalSrcIdx = 85;
                    section.data(27).dtTransOffset = 56;

                    ;% flightControlSystem_P.ControlSystem.N_Value
                    section.data(28).logicalSrcIdx = 86;
                    section.data(28).dtTransOffset = 57;

                    ;% flightControlSystem_P.ControlSystem.gravity_Value
                    section.data(29).logicalSrcIdx = 87;
                    section.data(29).dtTransOffset = 58;

                    ;% flightControlSystem_P.ControlSystem.Q_Value
                    section.data(30).logicalSrcIdx = 88;
                    section.data(30).dtTransOffset = 61;

                    ;% flightControlSystem_P.ControlSystem.R_Value
                    section.data(31).logicalSrcIdx = 89;
                    section.data(31).dtTransOffset = 62;

                    ;% flightControlSystem_P.ControlSystem.CovarianceZ_Value_b
                    section.data(32).logicalSrcIdx = 90;
                    section.data(32).dtTransOffset = 63;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainL_Value_l
                    section.data(33).logicalSrcIdx = 91;
                    section.data(33).dtTransOffset = 67;

                    ;% flightControlSystem_P.ControlSystem.CovarianceZ_Value_m
                    section.data(34).logicalSrcIdx = 92;
                    section.data(34).dtTransOffset = 69;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainL_Value_p
                    section.data(35).logicalSrcIdx = 93;
                    section.data(35).dtTransOffset = 73;

                    ;% flightControlSystem_P.ControlSystem.gravity_Value_p
                    section.data(36).logicalSrcIdx = 94;
                    section.data(36).dtTransOffset = 75;

                    ;% flightControlSystem_P.ControlSystem.gainaccinput1_Gain
                    section.data(37).logicalSrcIdx = 95;
                    section.data(37).dtTransOffset = 78;

                    ;% flightControlSystem_P.ControlSystem.CovarianceZ_Value_p
                    section.data(38).logicalSrcIdx = 96;
                    section.data(38).dtTransOffset = 79;

                    ;% flightControlSystem_P.ControlSystem.KalmanGainL_Value_k
                    section.data(39).logicalSrcIdx = 97;
                    section.data(39).dtTransOffset = 95;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 110;
            section.data(110)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.takeoff_gain1_Gain
                    section.data(1).logicalSrcIdx = 98;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.P_z1_Gain
                    section.data(2).logicalSrcIdx = 99;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.D_z1_Gain
                    section.data(3).logicalSrcIdx = 100;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.Pitchcorrection_Value
                    section.data(4).logicalSrcIdx = 101;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.zerocorrection_Value
                    section.data(5).logicalSrcIdx = 102;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_P.ControlSystem.Gain_Gain
                    section.data(6).logicalSrcIdx = 103;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_P.ControlSystem._Value_i
                    section.data(7).logicalSrcIdx = 104;
                    section.data(7).dtTransOffset = 7;

                    ;% flightControlSystem_P.ControlSystem.Gain_Gain_k
                    section.data(8).logicalSrcIdx = 105;
                    section.data(8).dtTransOffset = 8;

                    ;% flightControlSystem_P.ControlSystem.Out1_Y0
                    section.data(9).logicalSrcIdx = 106;
                    section.data(9).dtTransOffset = 9;

                    ;% flightControlSystem_P.ControlSystem.Lykyhatkk1_Y0_c
                    section.data(10).logicalSrcIdx = 107;
                    section.data(10).dtTransOffset = 10;

                    ;% flightControlSystem_P.ControlSystem.deltax_Y0_k
                    section.data(11).logicalSrcIdx = 108;
                    section.data(11).dtTransOffset = 11;

                    ;% flightControlSystem_P.ControlSystem.Gain_Gain_p
                    section.data(12).logicalSrcIdx = 109;
                    section.data(12).dtTransOffset = 12;

                    ;% flightControlSystem_P.ControlSystem.opticalFlowErrorCorrect_Gain
                    section.data(13).logicalSrcIdx = 110;
                    section.data(13).dtTransOffset = 13;

                    ;% flightControlSystem_P.ControlSystem.SimplyIntegrateVelocity_gainval
                    section.data(14).logicalSrcIdx = 111;
                    section.data(14).dtTransOffset = 14;

                    ;% flightControlSystem_P.ControlSystem.SimplyIntegrateVelocity_IC
                    section.data(15).logicalSrcIdx = 112;
                    section.data(15).dtTransOffset = 15;

                    ;% flightControlSystem_P.ControlSystem.invertzaxisGain_Gain
                    section.data(16).logicalSrcIdx = 113;
                    section.data(16).dtTransOffset = 16;

                    ;% flightControlSystem_P.ControlSystem.prsToAltGain_Gain
                    section.data(17).logicalSrcIdx = 114;
                    section.data(17).dtTransOffset = 17;

                    ;% flightControlSystem_P.ControlSystem.pressureFilter_IIR_NumCoef
                    section.data(18).logicalSrcIdx = 115;
                    section.data(18).dtTransOffset = 18;

                    ;% flightControlSystem_P.ControlSystem.pressureFilter_IIR_DenCoef
                    section.data(19).logicalSrcIdx = 116;
                    section.data(19).dtTransOffset = 22;

                    ;% flightControlSystem_P.ControlSystem.pressureFilter_IIR_InitialStates
                    section.data(20).logicalSrcIdx = 117;
                    section.data(20).dtTransOffset = 26;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_gainval
                    section.data(21).logicalSrcIdx = 118;
                    section.data(21).dtTransOffset = 27;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_IC
                    section.data(22).logicalSrcIdx = 119;
                    section.data(22).dtTransOffset = 28;

                    ;% flightControlSystem_P.ControlSystem.C_Value_h
                    section.data(23).logicalSrcIdx = 120;
                    section.data(23).dtTransOffset = 29;

                    ;% flightControlSystem_P.ControlSystem.Assumingthatthepreflightcalibrationwasdoneatlevelorientation_Bi
                    section.data(24).logicalSrcIdx = 121;
                    section.data(24).dtTransOffset = 31;

                    ;% flightControlSystem_P.ControlSystem.inverseIMU_gain_Gain
                    section.data(25).logicalSrcIdx = 122;
                    section.data(25).dtTransOffset = 37;

                    ;% flightControlSystem_P.ControlSystem.FIR_IMUaccel_InitialStates
                    section.data(26).logicalSrcIdx = 123;
                    section.data(26).dtTransOffset = 43;

                    ;% flightControlSystem_P.ControlSystem.FIR_IMUaccel_Coefficients
                    section.data(27).logicalSrcIdx = 124;
                    section.data(27).dtTransOffset = 44;

                    ;% flightControlSystem_P.ControlSystem.Gain2_Gain
                    section.data(28).logicalSrcIdx = 125;
                    section.data(28).dtTransOffset = 50;

                    ;% flightControlSystem_P.ControlSystem.X0_Value_i
                    section.data(29).logicalSrcIdx = 126;
                    section.data(29).dtTransOffset = 51;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_h
                    section.data(30).logicalSrcIdx = 127;
                    section.data(30).dtTransOffset = 53;

                    ;% flightControlSystem_P.ControlSystem.C_Value_i
                    section.data(31).logicalSrcIdx = 128;
                    section.data(31).dtTransOffset = 54;

                    ;% flightControlSystem_P.ControlSystem.X0_Value_iy
                    section.data(32).logicalSrcIdx = 129;
                    section.data(32).dtTransOffset = 56;

                    ;% flightControlSystem_P.ControlSystem.C_Value_i2
                    section.data(33).logicalSrcIdx = 130;
                    section.data(33).dtTransOffset = 58;

                    ;% flightControlSystem_P.ControlSystem.LPFFcutoff40Hz1_NumCoef
                    section.data(34).logicalSrcIdx = 131;
                    section.data(34).dtTransOffset = 66;

                    ;% flightControlSystem_P.ControlSystem.LPFFcutoff40Hz1_DenCoef
                    section.data(35).logicalSrcIdx = 132;
                    section.data(35).dtTransOffset = 68;

                    ;% flightControlSystem_P.ControlSystem.LPFFcutoff40Hz1_InitialStates
                    section.data(36).logicalSrcIdx = 133;
                    section.data(36).dtTransOffset = 70;

                    ;% flightControlSystem_P.ControlSystem.LPFFcutoff40Hz_NumCoef
                    section.data(37).logicalSrcIdx = 134;
                    section.data(37).dtTransOffset = 71;

                    ;% flightControlSystem_P.ControlSystem.LPFFcutoff40Hz_DenCoef
                    section.data(38).logicalSrcIdx = 135;
                    section.data(38).dtTransOffset = 73;

                    ;% flightControlSystem_P.ControlSystem.LPFFcutoff40Hz_InitialStates
                    section.data(39).logicalSrcIdx = 136;
                    section.data(39).dtTransOffset = 75;

                    ;% flightControlSystem_P.ControlSystem.IIR_IMUgyro_r_NumCoef
                    section.data(40).logicalSrcIdx = 137;
                    section.data(40).dtTransOffset = 76;

                    ;% flightControlSystem_P.ControlSystem.IIR_IMUgyro_r_DenCoef
                    section.data(41).logicalSrcIdx = 138;
                    section.data(41).dtTransOffset = 82;

                    ;% flightControlSystem_P.ControlSystem.IIR_IMUgyro_r_InitialStates
                    section.data(42).logicalSrcIdx = 139;
                    section.data(42).dtTransOffset = 88;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_j
                    section.data(43).logicalSrcIdx = 140;
                    section.data(43).dtTransOffset = 89;

                    ;% flightControlSystem_P.ControlSystem.Gain1_Gain
                    section.data(44).logicalSrcIdx = 141;
                    section.data(44).dtTransOffset = 90;

                    ;% flightControlSystem_P.ControlSystem.X0_Value_c
                    section.data(45).logicalSrcIdx = 142;
                    section.data(45).dtTransOffset = 91;

                    ;% flightControlSystem_P.ControlSystem.IIRgyroz_NumCoef
                    section.data(46).logicalSrcIdx = 143;
                    section.data(46).dtTransOffset = 95;

                    ;% flightControlSystem_P.ControlSystem.IIRgyroz_DenCoef
                    section.data(47).logicalSrcIdx = 144;
                    section.data(47).dtTransOffset = 101;

                    ;% flightControlSystem_P.ControlSystem.IIRgyroz_InitialStates
                    section.data(48).logicalSrcIdx = 145;
                    section.data(48).dtTransOffset = 107;

                    ;% flightControlSystem_P.ControlSystem.TSamp_WtEt
                    section.data(49).logicalSrcIdx = 146;
                    section.data(49).dtTransOffset = 108;

                    ;% flightControlSystem_P.ControlSystem.Delay_InitialCondition
                    section.data(50).logicalSrcIdx = 147;
                    section.data(50).dtTransOffset = 109;

                    ;% flightControlSystem_P.ControlSystem.Delay1_InitialCondition
                    section.data(51).logicalSrcIdx = 148;
                    section.data(51).dtTransOffset = 110;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_gainval_n
                    section.data(52).logicalSrcIdx = 149;
                    section.data(52).dtTransOffset = 111;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_IC_h
                    section.data(53).logicalSrcIdx = 150;
                    section.data(53).dtTransOffset = 112;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_UpperSat
                    section.data(54).logicalSrcIdx = 151;
                    section.data(54).dtTransOffset = 113;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_LowerSat
                    section.data(55).logicalSrcIdx = 152;
                    section.data(55).dtTransOffset = 114;

                    ;% flightControlSystem_P.ControlSystem.I_pr_Gain
                    section.data(56).logicalSrcIdx = 153;
                    section.data(56).dtTransOffset = 115;

                    ;% flightControlSystem_P.ControlSystem.w1_Value
                    section.data(57).logicalSrcIdx = 154;
                    section.data(57).dtTransOffset = 116;

                    ;% flightControlSystem_P.ControlSystem.SaturationThrust1_UpperSat
                    section.data(58).logicalSrcIdx = 155;
                    section.data(58).dtTransOffset = 117;

                    ;% flightControlSystem_P.ControlSystem.SaturationThrust1_LowerSat
                    section.data(59).logicalSrcIdx = 156;
                    section.data(59).dtTransOffset = 118;

                    ;% flightControlSystem_P.ControlSystem.Integrator_gainval
                    section.data(60).logicalSrcIdx = 157;
                    section.data(60).dtTransOffset = 119;

                    ;% flightControlSystem_P.ControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
                    section.data(61).logicalSrcIdx = 158;
                    section.data(61).dtTransOffset = 120;

                    ;% flightControlSystem_P.ControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_c
                    section.data(62).logicalSrcIdx = 159;
                    section.data(62).dtTransOffset = 122;

                    ;% flightControlSystem_P.ControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_l
                    section.data(63).logicalSrcIdx = 160;
                    section.data(63).dtTransOffset = 124;

                    ;% flightControlSystem_P.ControlSystem.Clamping_zero_Value
                    section.data(64).logicalSrcIdx = 161;
                    section.data(64).dtTransOffset = 125;

                    ;% flightControlSystem_P.ControlSystem.Integrator_gainval_i
                    section.data(65).logicalSrcIdx = 162;
                    section.data(65).dtTransOffset = 126;

                    ;% flightControlSystem_P.ControlSystem.Filter_gainval
                    section.data(66).logicalSrcIdx = 163;
                    section.data(66).dtTransOffset = 127;

                    ;% flightControlSystem_P.ControlSystem.Constant1_Value
                    section.data(67).logicalSrcIdx = 164;
                    section.data(67).dtTransOffset = 128;

                    ;% flightControlSystem_P.ControlSystem.TorqueTotalThrustToThrustPerMotor_Value
                    section.data(68).logicalSrcIdx = 165;
                    section.data(68).dtTransOffset = 129;

                    ;% flightControlSystem_P.ControlSystem.Saturation_UpperSat
                    section.data(69).logicalSrcIdx = 166;
                    section.data(69).dtTransOffset = 145;

                    ;% flightControlSystem_P.ControlSystem.Saturation_LowerSat
                    section.data(70).logicalSrcIdx = 167;
                    section.data(70).dtTransOffset = 146;

                    ;% flightControlSystem_P.ControlSystem.P_yaw_Gain
                    section.data(71).logicalSrcIdx = 168;
                    section.data(71).dtTransOffset = 147;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_gainval_d
                    section.data(72).logicalSrcIdx = 169;
                    section.data(72).dtTransOffset = 148;

                    ;% flightControlSystem_P.ControlSystem.DiscreteTimeIntegrator_IC_b
                    section.data(73).logicalSrcIdx = 170;
                    section.data(73).dtTransOffset = 149;

                    ;% flightControlSystem_P.ControlSystem.D_yaw_Gain
                    section.data(74).logicalSrcIdx = 171;
                    section.data(74).dtTransOffset = 150;

                    ;% flightControlSystem_P.ControlSystem.Clamping_zero_Value_m
                    section.data(75).logicalSrcIdx = 172;
                    section.data(75).dtTransOffset = 151;

                    ;% flightControlSystem_P.ControlSystem.Constant1_Value_c
                    section.data(76).logicalSrcIdx = 173;
                    section.data(76).dtTransOffset = 152;

                    ;% flightControlSystem_P.ControlSystem.I_yaw_Gain
                    section.data(77).logicalSrcIdx = 174;
                    section.data(77).dtTransOffset = 153;

                    ;% flightControlSystem_P.ControlSystem.ThrustToMotorCommand_Gain
                    section.data(78).logicalSrcIdx = 175;
                    section.data(78).dtTransOffset = 154;

                    ;% flightControlSystem_P.ControlSystem.Saturation5_UpperSat
                    section.data(79).logicalSrcIdx = 176;
                    section.data(79).dtTransOffset = 155;

                    ;% flightControlSystem_P.ControlSystem.Saturation5_LowerSat
                    section.data(80).logicalSrcIdx = 177;
                    section.data(80).dtTransOffset = 156;

                    ;% flightControlSystem_P.ControlSystem.MotorDirections_Gain
                    section.data(81).logicalSrcIdx = 178;
                    section.data(81).dtTransOffset = 157;

                    ;% flightControlSystem_P.ControlSystem.Gain_Gain_o
                    section.data(82).logicalSrcIdx = 179;
                    section.data(82).dtTransOffset = 161;

                    ;% flightControlSystem_P.ControlSystem.Gain1_Gain_p
                    section.data(83).logicalSrcIdx = 180;
                    section.data(83).dtTransOffset = 162;

                    ;% flightControlSystem_P.ControlSystem.A_Value_k
                    section.data(84).logicalSrcIdx = 181;
                    section.data(84).dtTransOffset = 163;

                    ;% flightControlSystem_P.ControlSystem.B_Value_o
                    section.data(85).logicalSrcIdx = 182;
                    section.data(85).dtTransOffset = 167;

                    ;% flightControlSystem_P.ControlSystem.D_Value_k
                    section.data(86).logicalSrcIdx = 183;
                    section.data(86).dtTransOffset = 169;

                    ;% flightControlSystem_P.ControlSystem.P0_Value_h
                    section.data(87).logicalSrcIdx = 184;
                    section.data(87).dtTransOffset = 170;

                    ;% flightControlSystem_P.ControlSystem.G_Value_m
                    section.data(88).logicalSrcIdx = 185;
                    section.data(88).dtTransOffset = 174;

                    ;% flightControlSystem_P.ControlSystem.H_Value_a
                    section.data(89).logicalSrcIdx = 186;
                    section.data(89).dtTransOffset = 178;

                    ;% flightControlSystem_P.ControlSystem.N_Value_f
                    section.data(90).logicalSrcIdx = 187;
                    section.data(90).dtTransOffset = 180;

                    ;% flightControlSystem_P.ControlSystem.Q_Value_j
                    section.data(91).logicalSrcIdx = 188;
                    section.data(91).dtTransOffset = 182;

                    ;% flightControlSystem_P.ControlSystem.R_Value_a
                    section.data(92).logicalSrcIdx = 189;
                    section.data(92).dtTransOffset = 186;

                    ;% flightControlSystem_P.ControlSystem.A_Value_a
                    section.data(93).logicalSrcIdx = 190;
                    section.data(93).dtTransOffset = 187;

                    ;% flightControlSystem_P.ControlSystem.B_Value_g
                    section.data(94).logicalSrcIdx = 191;
                    section.data(94).dtTransOffset = 191;

                    ;% flightControlSystem_P.ControlSystem.D_Value_ke
                    section.data(95).logicalSrcIdx = 192;
                    section.data(95).dtTransOffset = 193;

                    ;% flightControlSystem_P.ControlSystem.P0_Value_l
                    section.data(96).logicalSrcIdx = 193;
                    section.data(96).dtTransOffset = 194;

                    ;% flightControlSystem_P.ControlSystem.G_Value_g
                    section.data(97).logicalSrcIdx = 194;
                    section.data(97).dtTransOffset = 198;

                    ;% flightControlSystem_P.ControlSystem.H_Value_o
                    section.data(98).logicalSrcIdx = 195;
                    section.data(98).dtTransOffset = 202;

                    ;% flightControlSystem_P.ControlSystem.N_Value_b
                    section.data(99).logicalSrcIdx = 196;
                    section.data(99).dtTransOffset = 204;

                    ;% flightControlSystem_P.ControlSystem.Q_Value_p
                    section.data(100).logicalSrcIdx = 197;
                    section.data(100).dtTransOffset = 206;

                    ;% flightControlSystem_P.ControlSystem.R_Value_l
                    section.data(101).logicalSrcIdx = 198;
                    section.data(101).dtTransOffset = 210;

                    ;% flightControlSystem_P.ControlSystem.A_Value_a4
                    section.data(102).logicalSrcIdx = 199;
                    section.data(102).dtTransOffset = 211;

                    ;% flightControlSystem_P.ControlSystem.B_Value_f
                    section.data(103).logicalSrcIdx = 200;
                    section.data(103).dtTransOffset = 227;

                    ;% flightControlSystem_P.ControlSystem.D_Value_h
                    section.data(104).logicalSrcIdx = 201;
                    section.data(104).dtTransOffset = 235;

                    ;% flightControlSystem_P.ControlSystem.P0_Value_e
                    section.data(105).logicalSrcIdx = 202;
                    section.data(105).dtTransOffset = 239;

                    ;% flightControlSystem_P.ControlSystem.G_Value_i
                    section.data(106).logicalSrcIdx = 203;
                    section.data(106).dtTransOffset = 255;

                    ;% flightControlSystem_P.ControlSystem.H_Value_i
                    section.data(107).logicalSrcIdx = 204;
                    section.data(107).dtTransOffset = 271;

                    ;% flightControlSystem_P.ControlSystem.N_Value_i
                    section.data(108).logicalSrcIdx = 205;
                    section.data(108).dtTransOffset = 279;

                    ;% flightControlSystem_P.ControlSystem.Q_Value_m
                    section.data(109).logicalSrcIdx = 206;
                    section.data(109).dtTransOffset = 287;

                    ;% flightControlSystem_P.ControlSystem.R_Value_h
                    section.data(110).logicalSrcIdx = 207;
                    section.data(110).dtTransOffset = 303;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Output_InitialCondition
                    section.data(1).logicalSrcIdx = 208;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.Output_InitialCondition_e
                    section.data(2).logicalSrcIdx = 209;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.Output_InitialCondition_h
                    section.data(3).logicalSrcIdx = 210;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value
                    section.data(4).logicalSrcIdx = 211;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_a
                    section.data(5).logicalSrcIdx = 212;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value_m
                    section.data(6).logicalSrcIdx = 213;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_jy
                    section.data(7).logicalSrcIdx = 214;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value_p
                    section.data(8).logicalSrcIdx = 215;
                    section.data(8).dtTransOffset = 7;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_e
                    section.data(9).logicalSrcIdx = 216;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Output_InitialCondition_f
                    section.data(1).logicalSrcIdx = 217;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.FixPtConstant_Value_g
                    section.data(2).logicalSrcIdx = 218;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_k
                    section.data(3).logicalSrcIdx = 219;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.controlModePosVsOrient_Value
                    section.data(1).logicalSrcIdx = 220;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.isSqrtUsed_Value
                    section.data(2).logicalSrcIdx = 221;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.isSqrtUsed_Value_f
                    section.data(3).logicalSrcIdx = 222;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.isSqrtUsed_Value_j
                    section.data(4).logicalSrcIdx = 223;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.isSqrtUsed_Value_l
                    section.data(5).logicalSrcIdx = 224;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_km
                    section.data(1).logicalSrcIdx = 225;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.Constant2_Value
                    section.data(2).logicalSrcIdx = 226;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.Constant3_Value
                    section.data(3).logicalSrcIdx = 227;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.ControlSystem.Constant4_Value
                    section.data(4).logicalSrcIdx = 228;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.ControlSystem.Constant_Value_p
                    section.data(5).logicalSrcIdx = 229;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_P.ControlSystem.Constant2_Value_f
                    section.data(6).logicalSrcIdx = 230;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_P.ControlSystem.Constant3_Value_d
                    section.data(7).logicalSrcIdx = 231;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_P.ControlSystem.Constant4_Value_p
                    section.data(8).logicalSrcIdx = 232;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Disabletemperaturecompensation_CurrentSetting
                    section.data(1).logicalSrcIdx = 233;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.ControlSystem.ManualSwitch_CurrentSetting
                    section.data(2).logicalSrcIdx = 234;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.ControlSystem.Merge_InitialOutput
                    section.data(3).logicalSrcIdx = 235;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.EnabledSubsystem_n.deltax_Y0
                    section.data(1).logicalSrcIdx = 236;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.MeasurementUpdate_j.Lykyhatkk1_Y0
                    section.data(1).logicalSrcIdx = 237;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.EnabledSubsystem_d.deltax_Y0
                    section.data(1).logicalSrcIdx = 238;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.MeasurementUpdate_n.Lykyhatkk1_Y0
                    section.data(1).logicalSrcIdx = 239;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Normalcondition.Constant_Value
                    section.data(1).logicalSrcIdx = 240;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Ultrasoundimproper.Constant_Value
                    section.data(1).logicalSrcIdx = 241;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Noopticalflow.Constant_Value
                    section.data(1).logicalSrcIdx = 242;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.estimatorOpticalflowerror.Constant_Value
                    section.data(1).logicalSrcIdx = 243;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.ControlSystem.Geofencingerror.Constant_Value
                    section.data(1).logicalSrcIdx = 244;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(22) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 16;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (flightControlSystem_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.RateTransition
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.offset_x
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_B.R
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.G
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 19200;

                    ;% flightControlSystem_B.B
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 38400;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.BW
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.Reshapexhat
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.invertzaxisGain
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.ControlSystem.speed
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.ControlSystem.Sum
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.ControlSystem.Product2
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 5;

                    ;% flightControlSystem_B.ControlSystem.Product3
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 7;

                    ;% flightControlSystem_B.ControlSystem.z
                    section.data(6).logicalSrcIdx = 31;
                    section.data(6).dtTransOffset = 9;

                    ;% flightControlSystem_B.ControlSystem.x
                    section.data(7).logicalSrcIdx = 32;
                    section.data(7).dtTransOffset = 10;

                    ;% flightControlSystem_B.ControlSystem.y
                    section.data(8).logicalSrcIdx = 33;
                    section.data(8).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.SimplyIntegrateVelocity
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.DataTypeConversion
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.ControlSystem.inverseIMU_gain
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.ControlSystem.TrigonometricFunction1
                    section.data(3).logicalSrcIdx = 37;
                    section.data(3).dtTransOffset = 7;

                    ;% flightControlSystem_B.ControlSystem.TrigonometricFunction
                    section.data(4).logicalSrcIdx = 38;
                    section.data(4).dtTransOffset = 8;

                    ;% flightControlSystem_B.ControlSystem.DataTypeConversion3
                    section.data(5).logicalSrcIdx = 39;
                    section.data(5).dtTransOffset = 9;

                    ;% flightControlSystem_B.ControlSystem.p
                    section.data(6).logicalSrcIdx = 40;
                    section.data(6).dtTransOffset = 12;

                    ;% flightControlSystem_B.ControlSystem.q
                    section.data(7).logicalSrcIdx = 41;
                    section.data(7).dtTransOffset = 13;

                    ;% flightControlSystem_B.ControlSystem.Subtract
                    section.data(8).logicalSrcIdx = 42;
                    section.data(8).dtTransOffset = 14;

                    ;% flightControlSystem_B.ControlSystem.angularvelocitycompensation
                    section.data(9).logicalSrcIdx = 43;
                    section.data(9).dtTransOffset = 17;

                    ;% flightControlSystem_B.ControlSystem.DataTypeConversion2
                    section.data(10).logicalSrcIdx = 45;
                    section.data(10).dtTransOffset = 19;

                    ;% flightControlSystem_B.ControlSystem.TmpSignalConversionAtToWorkspaceInport1
                    section.data(11).logicalSrcIdx = 46;
                    section.data(11).dtTransOffset = 20;

                    ;% flightControlSystem_B.ControlSystem.Product
                    section.data(12).logicalSrcIdx = 47;
                    section.data(12).dtTransOffset = 32;

                    ;% flightControlSystem_B.ControlSystem.Product2_k
                    section.data(13).logicalSrcIdx = 48;
                    section.data(13).dtTransOffset = 34;

                    ;% flightControlSystem_B.ControlSystem.Product3_a
                    section.data(14).logicalSrcIdx = 49;
                    section.data(14).dtTransOffset = 38;

                    ;% flightControlSystem_B.ControlSystem.In1
                    section.data(15).logicalSrcIdx = 51;
                    section.data(15).dtTransOffset = 42;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.LogicalOperator
                    section.data(1).logicalSrcIdx = 53;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.Compare
                    section.data(1).logicalSrcIdx = 54;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.ControlSystem.nicemeasurementornewupdateneeded
                    section.data(2).logicalSrcIdx = 55;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.ControlSystem.LogicalOperator3
                    section.data(3).logicalSrcIdx = 56;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.EnabledSubsystem_n.Product2
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.MeasurementUpdate_j.Product3
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.EnabledSubsystem_d.Product2
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.ControlSystem.MeasurementUpdate_n.Product3
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(14) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%

                        ;% motors_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 268;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        sigMap.sections(15) = section;
                        clear section


                        ;% flag_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 269;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        sigMap.sections(16) = section;
                        clear section



        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 35;
        sectIdxOffset = 16;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (flightControlSystem_DW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.RateTransition_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.xy
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 10;

                    ;% flightControlSystem_DW.prev_endless_x
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 12;

                    ;% flightControlSystem_DW.prev_endless_y
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% flightControlSystem_DW.sfEvent
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.sfEvent_i
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.sfEvent_d
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.sfEvent_f
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.sfEvent_m
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_DW.sfEvent_a
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_DW.sfEvent_g
                    section.data(7).logicalSrcIdx = 11;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_DW.sfEvent_b
                    section.data(8).logicalSrcIdx = 12;
                    section.data(8).dtTransOffset = 7;

                    ;% flightControlSystem_DW.sfEvent_p
                    section.data(9).logicalSrcIdx = 13;
                    section.data(9).dtTransOffset = 8;

                    ;% flightControlSystem_DW.sfEvent_l
                    section.data(10).logicalSrcIdx = 14;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.obj
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.RateTransition_ActiveBufIdx
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% flightControlSystem_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_c
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_f
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_d
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_e
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_ey
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_DW.objisempty
                    section.data(7).logicalSrcIdx = 23;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_dl
                    section.data(8).logicalSrcIdx = 24;
                    section.data(8).dtTransOffset = 7;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_b
                    section.data(9).logicalSrcIdx = 25;
                    section.data(9).dtTransOffset = 8;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_g
                    section.data(10).logicalSrcIdx = 26;
                    section.data(10).dtTransOffset = 9;

                    ;% flightControlSystem_DW.prev_endless_x_not_empty
                    section.data(11).logicalSrcIdx = 27;
                    section.data(11).dtTransOffset = 10;

                    ;% flightControlSystem_DW.prev_endless_y_not_empty
                    section.data(12).logicalSrcIdx = 28;
                    section.data(12).dtTransOffset = 11;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_bw
                    section.data(13).logicalSrcIdx = 29;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Delay2_DSTATE
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.ControlSystem.sonarFilter_IIR_states
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 3;

                    ;% flightControlSystem_DW.ControlSystem.DelayOneStep_DSTATE
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.ToWorkspace_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_DSTATE
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.pressureFilter_IIR_states
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 2;

                    ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 5;

                    ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_states
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 6;

                    ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE_g
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 21;

                    ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE_m
                    section.data(6).logicalSrcIdx = 41;
                    section.data(6).dtTransOffset = 23;

                    ;% flightControlSystem_DW.ControlSystem.LPFFcutoff40Hz1_states
                    section.data(7).logicalSrcIdx = 42;
                    section.data(7).dtTransOffset = 25;

                    ;% flightControlSystem_DW.ControlSystem.LPFFcutoff40Hz_states
                    section.data(8).logicalSrcIdx = 43;
                    section.data(8).dtTransOffset = 26;

                    ;% flightControlSystem_DW.ControlSystem.IIR_IMUgyro_r_states
                    section.data(9).logicalSrcIdx = 44;
                    section.data(9).dtTransOffset = 27;

                    ;% flightControlSystem_DW.ControlSystem.MemoryX_DSTATE_l
                    section.data(10).logicalSrcIdx = 45;
                    section.data(10).dtTransOffset = 32;

                    ;% flightControlSystem_DW.ControlSystem.IIRgyroz_states
                    section.data(11).logicalSrcIdx = 46;
                    section.data(11).dtTransOffset = 36;

                    ;% flightControlSystem_DW.ControlSystem.UD_DSTATE
                    section.data(12).logicalSrcIdx = 47;
                    section.data(12).dtTransOffset = 46;

                    ;% flightControlSystem_DW.ControlSystem.Delay_DSTATE
                    section.data(13).logicalSrcIdx = 48;
                    section.data(13).dtTransOffset = 48;

                    ;% flightControlSystem_DW.ControlSystem.Delay1_DSTATE
                    section.data(14).logicalSrcIdx = 49;
                    section.data(14).dtTransOffset = 50;

                    ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE_c
                    section.data(15).logicalSrcIdx = 50;
                    section.data(15).dtTransOffset = 52;

                    ;% flightControlSystem_DW.ControlSystem.Integrator_DSTATE
                    section.data(16).logicalSrcIdx = 51;
                    section.data(16).dtTransOffset = 53;

                    ;% flightControlSystem_DW.ControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrolle
                    section.data(17).logicalSrcIdx = 52;
                    section.data(17).dtTransOffset = 55;

                    ;% flightControlSystem_DW.ControlSystem.Integrator_DSTATE_d
                    section.data(18).logicalSrcIdx = 53;
                    section.data(18).dtTransOffset = 57;

                    ;% flightControlSystem_DW.ControlSystem.Filter_DSTATE
                    section.data(19).logicalSrcIdx = 54;
                    section.data(19).dtTransOffset = 59;

                    ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_DSTATE_d
                    section.data(20).logicalSrcIdx = 55;
                    section.data(20).dtTransOffset = 61;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_circBuf
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Output_DSTATE
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_i
                    section.data(2).logicalSrcIdx = 58;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_g
                    section.data(3).logicalSrcIdx = 59;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_simContextBuf
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.FIR_IMUaccel_simRevCoeff
                    section.data(2).logicalSrcIdx = 62;
                    section.data(2).dtTransOffset = 30;

                    ;% flightControlSystem_DW.ControlSystem.IIRgyroz_tmp
                    section.data(3).logicalSrcIdx = 66;
                    section.data(3).dtTransOffset = 36;

                    ;% flightControlSystem_DW.ControlSystem.LPF8HzCutoffFiltertoavoidoscillationsinducedbypositioncontrol_j
                    section.data(4).logicalSrcIdx = 67;
                    section.data(4).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.sfEvent
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.sfEvent_n
                    section.data(2).logicalSrcIdx = 69;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.ControlSystem.sfEvent_j
                    section.data(3).logicalSrcIdx = 70;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.ControlSystem.sfEvent_p
                    section.data(4).logicalSrcIdx = 71;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.is_c3_flightControlSystem
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Output_DSTATE_a
                    section.data(1).logicalSrcIdx = 73;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.temporalCounter_i1
                    section.data(2).logicalSrcIdx = 74;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.SimplyIntegrateVelocity_PrevResetState
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.DiscreteTimeIntegrator_PrevResetState
                    section.data(2).logicalSrcIdx = 76;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC
                    section.data(3).logicalSrcIdx = 77;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC
                    section.data(4).logicalSrcIdx = 78;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.ControlSystem.TriggeredSubsystem_SubsysRanBC
                    section.data(5).logicalSrcIdx = 79;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_SubsysRanBC_c
                    section.data(6).logicalSrcIdx = 80;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_SubsysRanBC_m
                    section.data(7).logicalSrcIdx = 81;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.is_active_c3_flightControlSystem
                    section.data(1).logicalSrcIdx = 82;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.icLoad
                    section.data(1).logicalSrcIdx = 83;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.ControlSystem.icLoad_p
                    section.data(2).logicalSrcIdx = 84;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.ControlSystem.icLoad_k
                    section.data(3).logicalSrcIdx = 85;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.ControlSystem.icLoad_o
                    section.data(4).logicalSrcIdx = 86;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.ControlSystem.doneDoubleBufferReInit
                    section.data(5).logicalSrcIdx = 87;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_DW.ControlSystem.doneDoubleBufferReInit_i
                    section.data(6).logicalSrcIdx = 88;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_DW.ControlSystem.doneDoubleBufferReInit_j
                    section.data(7).logicalSrcIdx = 89;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_MODE
                    section.data(8).logicalSrcIdx = 90;
                    section.data(8).dtTransOffset = 7;

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_MODE
                    section.data(9).logicalSrcIdx = 91;
                    section.data(9).dtTransOffset = 8;

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_MODE_l
                    section.data(10).logicalSrcIdx = 92;
                    section.data(10).dtTransOffset = 9;

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_MODE_c
                    section.data(11).logicalSrcIdx = 93;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC
                    section.data(1).logicalSrcIdx = 94;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_n.EnabledSubsystem_MODE
                    section.data(1).logicalSrcIdx = 95;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_j.MeasurementUpdate_SubsysRanBC
                    section.data(1).logicalSrcIdx = 96;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_j.MeasurementUpdate_MODE
                    section.data(1).logicalSrcIdx = 97;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.sf_SqrtUsedFcn_e.sfEvent
                    section.data(1).logicalSrcIdx = 98;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.sf_SqrtUsedFcn_e.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 99;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC
                    section.data(1).logicalSrcIdx = 100;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.EnabledSubsystem_d.EnabledSubsystem_MODE
                    section.data(1).logicalSrcIdx = 101;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_n.MeasurementUpdate_SubsysRanBC
                    section.data(1).logicalSrcIdx = 102;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.MeasurementUpdate_n.MeasurementUpdate_MODE
                    section.data(1).logicalSrcIdx = 103;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.sf_SqrtUsedFcn_h.sfEvent
                    section.data(1).logicalSrcIdx = 104;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(29) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.sf_SqrtUsedFcn_h.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 105;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(30) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Normalcondition.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 106;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(31) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Ultrasoundimproper.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 107;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(32) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Noopticalflow.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 108;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(33) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 109;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(34) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.ControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 110;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(35) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2527937286;
    targMap.checksum1 = 2026100765;
    targMap.checksum2 = 1997352618;
    targMap.checksum3 = 1500484846;

