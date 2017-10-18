///	@brief 		Unit test for the easing classes
///	@author		Nathan Wolek
//	@copyright	Copyright (c) 2017, Cycling '74
///	@license	This project is released under the terms of the MIT License.

#define CATCH_CONFIG_MAIN
#include "c74_min_catch.h"

// NW: Defining a macro for the test loop so that the syntax is consistent
// The number of steps in our test loop will be equal to the number of values in the reference sample_vector
#define EASING_TEST_LOOP(easing_function, reference_vector) { \
    for (auto i = 0; i < reference_vector.size(); ++i) { \
        auto x = i / double(reference_vector.size()-1); \
        INFO( "when i == " << i ); \
        REQUIRE( easing_function(x) == Approx(reference_vector[i]) ); \
    } \
} 

SCENARIO ("Using Linear Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        0,
        0.01587301587301587,
        0.03174603174603174,
        0.04761904761904762,
        0.06349206349206349,
        0.07936507936507936,
        0.09523809523809523,
        0.1111111111111111,
        0.126984126984127,
        0.1428571428571428,
        0.1587301587301587,
        0.1746031746031746,
        0.1904761904761905,
        0.2063492063492063,
        0.2222222222222222,
        0.2380952380952381,
        0.253968253968254,
        0.2698412698412698,
        0.2857142857142857,
        0.3015873015873016,
        0.3174603174603174,
        0.3333333333333333,
        0.3492063492063492,
        0.3650793650793651,
        0.3809523809523809,
        0.3968253968253968,
        0.4126984126984127,
        0.4285714285714285,
        0.4444444444444444,
        0.4603174603174603,
        0.4761904761904762,
        0.492063492063492,
        0.5079365079365079,
        0.5238095238095238,
        0.5396825396825397,
        0.5555555555555556,
        0.5714285714285714,
        0.5873015873015873,
        0.6031746031746031,
        0.6190476190476191,
        0.6349206349206349,
        0.6507936507936508,
        0.6666666666666666,
        0.6825396825396826,
        0.6984126984126984,
        0.7142857142857143,
        0.7301587301587301, 
        0.746031746031746, 
        0.7619047619047619, 
        0.7777777777777778, 
        0.7936507936507936, 
        0.8095238095238095, 
        0.8253968253968254, 
        0.8412698412698413, 
        0.8571428571428571, 
        0.873015873015873, 
        0.8888888888888888, 
        0.9047619047619048, 
        0.9206349206349206, 
        0.9365079365079365, 
        0.9523809523809523, 
        0.9682539682539683, 
        0.9841269841269841, 
        1
    };
    
	GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
		EASING_TEST_LOOP(c74::min::lib::easing::linear, reference);
	
	}
}

SCENARIO ("Using In Back Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        0,
        -0.0007872052861554308,
        -0.003128890033784019,
        -0.006989271070477585,
        -0.01232475562367729,
        -0.01908401443394193,
        -0.02720808377393558,
        -0.03663049603481367,
        -0.04727743844682841,
        -0.05906793940746457,
        -0.07191408179854235,
        -0.08572124258377627,
        -0.1003883578905333,
        -0.1158082126942681,
        -0.1318677541415904,
        -0.1484484274684027,
        -0.1654265333932787,
        -0.1826736057934785,
        -0.2000568084019443,
        -0.2174393491985045,
        -0.2346809111075447,
        -0.2516380975577758,
        -0.2681648914076146,
        -0.2841131256922727,
        -0.2993329646060633,
        -0.3136733930958325,
        -0.3269827134089173,
        -0.3391090469117437,
        -0.3499008394731898,
        -0.3592073686902318,
        -0.3668792512222226,
        -0.3727689484944767,
        -0.3767312690316608,
        -0.3786238656868486,
        -0.3783077260429712,
        -0.3756476542797589,
        -0.3705127428211004,
        -0.3627768321049648,
        -0.3523189568505887,
        -0.3390237772354198,
        -0.3227819934372388,
        -0.3034907420448214,
        -0.2810539728933296,
        -0.2553828049381625,
        -0.226395859843127,
        -0.1940195720252691,
        -0.1581884739694183,
        -0.1188454557001511, 
        -0.07594199737734691, 
        -0.02943837406346755, 
        0.02069616820401338, 
        0.07448326581330578, 
        0.1319353211392744, 
        0.1930554168582522, 
        0.2578372615143961, 
        0.3262651667375155, 
        0.3983140564128485, 
        0.4739495080024873, 
        0.553127826116286, 
        0.6357961483275298, 
        0.7218925831255953, 
        0.8113463797947321, 
        0.9040781299051253, 
        0.9999999999999999
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::in_back, reference);
        
    }
}

SCENARIO ("Using In Out Back Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        0,
        -0.00156444501689201,
        -0.006162377811838645,
        -0.01360404188696779,
        -0.02363871922341421,
        -0.03595704089927117,
        -0.05019417894526666,
        -0.06593387707079518,
        -0.08271326669663934,
        -0.1000284042009722,
        -0.1173404555537724,
        -0.1340824457038073,
        -0.1496664823030316,
        -0.1634913567044586,
        -0.1749504197365949,
        -0.1834396256111113,
        -0.1883656345158304,
        -0.1891538630214856,
        -0.1852563714105502,
        -0.1761594784252943,
        -0.1613909967186194,
        -0.1405269864466648,
        -0.1131979299215635,
        -0.07909423698470916,
        -0.03797099868867346,
        0.01034808410200669,
        0.06596766056963718,
        0.1289186307571981,
        0.1991570282064243,
        0.276563913058143,
        0.3609462915627977,
        0.4520390649525626,
        0.547960935047437,
        0.6390537084372023,
        0.7234360869418567,
        0.8008429717935758,
        0.8710813692428019,
        0.9340323394303628,
        0.9896519158979931,
        1.037970998688674,
        1.079094236984709,
        1.113197929921564,
        1.140526986446665,
        1.161390996718619,
        1.176159478425294,
        1.18525637141055,
        1.189153863021486, 
        1.18836563451583, 
        1.183439625611111, 
        1.174950419736595, 
        1.163491356704459, 
        1.149666482303032, 
        1.134082445703807, 
        1.117340455553772, 
        1.100028404200972, 
        1.082713266696639, 
        1.065933877070795, 
        1.050194178945267, 
        1.035957040899271, 
        1.023638719223414, 
        1.013604041886968, 
        1.006162377811838, 
        1.001564445016892, 
        1
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::in_out_back, reference);
        
    }
}

SCENARIO ("Using Out Back Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        1.110223024625157e-16,
        0.09592187009487396,
        0.1886536202052679,
        0.2781074168744047,
        0.3642038516724702,
        0.4468721738837134,
        0.5260504919975127,
        0.6016859435871516,
        0.6737348332624844,
        0.7421627384856038,
        0.8069445831417479,
        0.8680646788607256,
        0.9255167341866942,
        0.9793038317959861,
        1.029438374063468,
        1.075941997377347,
        1.118845455700151,
        1.158188473969418,
        1.194019572025269,
        1.226395859843127,
        1.255382804938162,
        1.281053972893329,
        1.303490742044821,
        1.322781993437239,
        1.33902377723542,
        1.352318956850588,
        1.362776832104965,
        1.3705127428211,
        1.375647654279759,
        1.378307726042971,
        1.378623865686849,
        1.376731269031661,
        1.372768948494477,
        1.366879251222223,
        1.359207368690232,
        1.34990083947319,
        1.339109046911744,
        1.326982713408917,
        1.313673393095833,
        1.299332964606063,
        1.284113125692273,
        1.268164891407614,
        1.251638097557776,
        1.234680911107545,
        1.217439349198504,
        1.200056808401944,
        1.182673605793479, 
        1.165426533393279, 
        1.148448427468403, 
        1.13186775414159, 
        1.115808212694268, 
        1.100388357890533, 
        1.085721242583776, 
        1.071914081798542, 
        1.059067939407465, 
        1.047277438446828, 
        1.036630496034814, 
        1.027208083773936, 
        1.019084014433942, 
        1.012324755623677, 
        1.006989271070478, 
        1.003128890033784, 
        1.000787205286156, 
        1
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::out_back, reference);
        
    }
}

SCENARIO ("Using Out Bounce Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        0,
        0.001905391786344167,
        0.007621567145376668,
        0.01714852607709751,
        0.03048626858150667,
        0.04763479465860418,
        0.06859410430839002,
        0.09336419753086418,
        0.1219450743260267,
        0.1543367346938775,
        0.1905391786344167,
        0.2305524061476442,
        0.2743764172335601,
        0.3220112118921643,
        0.3734567901234567,
        0.4287131519274376,
        0.4877802973041068,
        0.5506582262534644,
        0.6173469387755102,
        0.6878464348702442,
        0.7621567145376669,
        0.8402777777777777,
        0.9222096245905769,
        0.9952569916855629,
        0.9455782312925165,
        0.9004724111866969,
        0.8599395313681026,
        0.8239795918367343,
        0.7925925925925923,
        0.7657785336356766,
        0.7435374149659859,
        0.7258692365835224,
        0.7127739984882839,
        0.7042517006802718,
        0.7003023431594859,
        0.7009259259259255,
        0.706122448979591,
        0.7158919123204832,
        0.7302343159486009,
        0.7491496598639453,
        0.7726379440665148,
        0.800699168556311,
        0.8333333333333326,
        0.870540438397581,
        0.9123204837490539,
        0.9586734693877541,
        0.9940854642872861,
        0.9651484601227374, 
        0.9422918197750025, 
        0.9255155432440763, 
        0.9148196305299594, 
        0.9102040816326538, 
        0.9116688965521575, 
        0.9192140752884708, 
        0.9328396178415979, 
        0.9525455242115335, 
        0.9783317943982759, 
        0.9951020408163274, 
        0.9823129251700706, 
        0.9749659863945599, 
        0.9730612244897987, 
        0.9765986394557835, 
        0.9855782312925179, 
        1.000000000000002
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::out_bounce, reference);
        
    }
}

SCENARIO ("Using In Bounce Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        -1.77635683940025e-15,
        0.01442176870748213,
        0.02340136054421649,
        0.0269387755102013,
        0.02503401360544011,
        0.01768707482993115,
        0.00489795918367264,
        0.02166820560172411,
        0.04745447578846651,
        0.06716038215840392,
        0.08078592471152923,
        0.08833110344784245,
        0.08979591836734624,
        0.08518036947003971,
        0.07448445675592374,
        0.05770818022499746,
        0.03485153987726264,
        0.00591453571271483,
        0.04132653061224589,
        0.08767951625094605,
        0.129459561602419,
        0.1666666666666665,
        0.199300831443689,
        0.2273620559334852,
        0.2508503401360547,
        0.2697656840513991,
        0.2841080876795168,
        0.293877551020409,
        0.2990740740740745,
        0.2996976568405141,
        0.2957482993197282,
        0.2872260015117161,
        0.2741307634164785,
        0.2564625850340141,
        0.2342214663643243,
        0.2074074074074077,
        0.1760204081632653,
        0.1400604686318974,
        0.09952758881330359,
        0.0544217687074835,
        0.00474300831443708,
        0.07779037540942313,
        0.1597222222222221,
        0.2378432854623331,
        0.3121535651297555,
        0.3826530612244898,
        0.4493417737465354, 
        0.5122197026958932, 
        0.5712868480725621, 
        0.6265432098765433, 
        0.6779887881078357, 
        0.7256235827664399, 
        0.7694475938523556, 
        0.8094608213655833, 
        0.8456632653061223, 
        0.8780549256739734, 
        0.9066358024691357, 
        0.93140589569161, 
        0.9523652053413958, 
        0.9695137314184933, 
        0.9828514739229025, 
        0.9923784328546233, 
        0.9980946082136558, 
        1
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::in_bounce, reference);
        
    }
}

SCENARIO ("Using In Out Bounce Easing") {
    
    // The following output was generated using the Octave code in EasingTargetOutput.m by NW
    c74::min::sample_vector reference = {
        -8.881784197001252e-16,
        0.01170068027210824,
        0.01251700680272005,
        0.00244897959183632,
        0.02372723789423326,
        0.04039296235576462,
        0.04489795918367312,
        0.03724222837796187,
        0.01742576993863132,
        0.02066326530612295,
        0.0647297808012095,
        0.09965041572184452,
        0.1254251700680273,
        0.1420540438397584,
        0.1495370370370372,
        0.1478741496598641,
        0.1370653817082392,
        0.1171107331821621,
        0.08801020408163263,
        0.0497637944066518,
        0.00237150415721854,
        0.07986111111111105,
        0.1560767825648777,
        0.2246708868732677,
        0.2856434240362811,
        0.3389943940539178,
        0.3847237969261778,
        0.4228316326530612,
        0.4533179012345678,
        0.4761826026706979,
        0.4914257369614513,
        0.4990473041068279,
        0.500952695893172,
        0.5085742630385488,
        0.5238173973293021,
        0.5466820987654322,
        0.5771683673469387,
        0.6152762030738221,
        0.661005605946082,
        0.7143565759637189,
        0.775329113126732,
        0.8439232174351223,
        0.9201388888888886,
        0.9976284958427815,
        0.9502362055933484,
        0.9119897959183674,
        0.8828892668178379,
        0.8629346182917608, 
        0.8521258503401359, 
        0.8504629629629628, 
        0.8579459561602412, 
        0.8745748299319727, 
        0.9003495842781555, 
        0.9352702191987905, 
        0.9793367346938771, 
        0.9825742300613687, 
        0.9627577716220377, 
        0.9551020408163269, 
        0.9596070376442363, 
        0.9762727621057667, 
        0.9975510204081646, 
        0.9874829931972799, 
        0.9882993197278926, 
        1.000000000000001
    };
    
    GIVEN ("A loop that generates input of evenly-spaced steps from 0.0 to 1.0"){
        THEN("The output matches an externally generated reference set.")
        
        EASING_TEST_LOOP(c74::min::lib::easing::in_out_bounce, reference);
        
    }
}