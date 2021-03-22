#include "..\..\head\model\model.h"
#include "..\..\head\transformations\transformations.h"
#include "..\..\head\binaryzation\binaryzation.h"
#include "..\..\head\goldwasser_micali\goldwasser_micali.h"

#include<iostream>

#define SIZE 128

float stu_1[SIZE] = {
	-0.05090385, 0.03726890, 0.05515366, -0.05376638, -0.15249203, 0.02836201, -0.06384426, -0.08155162, 0.07254539, -0.17092977, 0.19646198, -0.03493685, -0.18262079, -0.06233163, -0.06381864, 0.16623129, -0.13379939, -0.14056538, -0.05347563, 0.00153044, 0.06286752, 0.06597989, -0.01534997, 0.00040506, -0.14274769, -0.30505785, -0.06413636, -0.03537826, -0.00306843, -0.06719697, -0.07277402, 0.04915644, -0.16551809, -0.00520779, 0.01798618, 0.07593899, -0.04890823, -0.00980740, 0.17715241, 0.05972235, -0.23733044, 0.08986593, 0.02108277, 0.27924776, 0.18533221, 0.03887320, 0.01178757, -0.11968131, 0.13148807, -0.18335922, 0.02190506, 0.16252679, 0.10276131, 0.06684782, -0.03248299, -0.07994293, 0.04862234, 0.08299588, -0.09005304, 0.04014735, 0.11184291, -0.06877517, 0.00896598, -0.10363295, 0.20887262, -0.03903368, -0.11467087, -0.14403944, 0.09760121, -0.15366736, -0.12614931, 0.01764217, -0.15932681, -0.16351216, -0.28571829, 0.02446724, 0.36367503, 0.16190436, -0.19151367, 0.06982940, -0.01613083, 0.00697669, 0.11754268, 0.15864870, -0.02987479, 0.05854640, -0.03464558, 0.02880486, 0.23980302, -0.07051760, -0.00496709, 0.24479194, 0.05007882, 0.09949476, 0.05192781, -0.03285740, -0.03170419, 0.02970810, -0.09362688, 0.04099543, 0.00688456, -0.10565528, 0.04607218, 0.12451649, -0.16289249, 0.23570010, -0.04811502, 0.07532810, 0.05127224, 0.05247771, -0.11377426, -0.06923114, 0.13754763, -0.19117323, 0.15650809, 0.20822738, 0.10830509, 0.08089101, 0.17635199, 0.09774975, -0.03654426, 0.06833761, -0.22735700, -0.03974560, 0.10314336, -0.08864537, 0.10882093, 0.04410089
};

float stu_2[SIZE] = {
	-0.03034532, 0.03974929, 0.05748067, -0.03205561, -0.12204697, 0.02641506, -0.05164246, -0.11226365, 0.08368196, -0.15537333, 0.19558536, -0.03892838, -0.17665642, -0.07587177, -0.07930434, 0.16531484, -0.15135741, -0.14284758, -0.04178578, -0.01699325, 0.07967852, 0.07418834, -0.02111208, -0.01068855, -0.14584854, -0.26678032, -0.07535858, -0.05758125, 0.00117888, -0.05519878, -0.08439867, 0.06952933, -0.17227498, -0.01288724, 0.02720878, 0.06307633, -0.06070124, -0.01086143, 0.16921587, 0.04497451, -0.20012312, 0.11557767, 0.05037016, 0.27337807, 0.20677382, 0.03057613, -0.01107736, -0.10923838, 0.12085941, -0.18276237, -0.00363738, 0.17490228, 0.13062607, 0.08319078, -0.03262256, -0.07811193, 0.03593182, 0.07607763, -0.11197458, 0.07457718, 0.12674153, -0.10745893, 0.00735236, -0.08083370, 0.21618094, -0.02075482, -0.12501650, -0.14748779, 0.09596220, -0.15867934, -0.13157073, 0.00418507, -0.16537227, -0.16077545, -0.27628884, 0.02793062, 0.34808347, 0.14119998, -0.18401834, 0.09023912, -0.01820273, 0.02105687, 0.10877579, 0.14383109, -0.03319607, 0.03252123, -0.04529225, 0.02115780, 0.23915839, -0.07798800, -0.00757866, 0.24943621, 0.01544445, 0.08203261, 0.04169163, -0.04313462, -0.03026685, 0.02240387, -0.10110952, 0.04069553, -0.01575151, -0.11560403, 0.04879417, 0.12305038, -0.12881997, 0.19555894, -0.05846423, 0.07565383, 0.03405949, 0.02302106, -0.13553943, -0.04555625, 0.13772006, -0.19909666, 0.19424894, 0.17669325, 0.10536478, 0.06754375, 0.17296699, 0.09820855, -0.03524624, 0.06447944, -0.21710767, -0.04506215, 0.11182901, -0.08488229, 0.11558737, 0.03799019
};

float student_1_0[SIZE] = {
	-0.167532846, -0.006073730, -0.025167335, -0.076719016, -0.143915653, -0.026436377, 0.007104250, -0.099421524, 0.174190938, -0.068219639, 0.213096097, -0.075516798, -0.181405529, -0.042870723, -0.095428079, 0.185171932, -0.193645433, -0.122666277, -0.007833946, 0.002643245, 0.080544278, 0.014148206, -0.045723427, 0.059342429, -0.085158736, -0.352025181, -0.078207560, -0.083991788, 0.051964249, -0.041902587, 0.005995143, 0.082780100, -0.213857695, -0.102244042, 0.069199301, 0.117261156, 0.001520938, -0.072428763, 0.172821432, 0.019904567, -0.223661467, -0.013678405, 0.115146279, 0.248741508, 0.090243094, 0.079860836, 0.007192972, -0.108966842, 0.130677491, -0.153036952, -0.017762674, 0.091359623, 0.081926987, 0.038285200, -0.009162217, -0.124979988, 0.092670053, 0.064237833, -0.178170055, 0.015699150, 0.098575763, -0.062903836, -0.030357875, -0.060337164, 0.202862740, 0.016819086, -0.045670815, -0.195353732, 0.139573827, -0.145419791, -0.130919173, 0.035659153, -0.127212912, -0.164778039, -0.315876424, -0.008683130, 0.388655066, 0.114307836, -0.128524005, 0.102226853, 0.010503412, -0.009926913, 0.141132399, 0.126522899, 0.000508318, 0.060902573, -0.086018078, -0.019246558, 0.249786571, -0.027452054, -0.033447389, 0.154319689, -0.002330432, 0.059636127, 0.026494777, 0.011385595, -0.060690176, 0.055823293, -0.126545221, -0.045731176, 0.105639353, 0.028431084, 0.040419411, 0.119408116, -0.201820612, 0.117035568, -0.026916677, -0.000123897, 0.000793105, -0.003352039, -0.102420963, -0.002904223, 0.110778257, -0.196232781, 0.231528714, 0.188535213, 0.072409049, 0.102512315, 0.132215843, -0.008519615, 0.012714202, 0.025931854, -0.218082070, -0.086899444, 0.097187035, -0.062116880, 0.107382491, -0.000502559
};

float student_1_1[SIZE] = {
	-0.093008898, 0.069709681, 0.012965566, 0.017904006, -0.104149505, -0.007361774, -0.006104713, -0.084292889, 0.115906559, -0.084572352, 0.240213707, -0.068667233, -0.204982489, -0.025900412, -0.072395541, 0.120389387, -0.184463352, -0.128690690, -0.064430661, -0.053512789, 0.090787880, 0.058987655, 0.005280658, 0.030154213, -0.026683997, -0.353399038, -0.086410768, -0.116742238, 0.083815575, -0.043064725, -0.021008503, 0.014781936, -0.137648329, -0.071892202, 0.106413409, 0.080423526, 0.017127322, -0.045422982, 0.198949009, 0.018420111, -0.136843204, 0.040770307, 0.080649942, 0.287140101, 0.163560539, 0.130446285, -0.015669530, -0.205358237, 0.154670000, -0.128914863, 0.018277710, 0.177432537, 0.124078058, 0.076296233, 0.044063751, -0.103918388, 0.066186629, 0.047945369, -0.152313262, 0.063952975, 0.067246079, -0.052055489, 0.042264894, -0.080236882, 0.209489301, -0.023726923, -0.079258926, -0.180358261, 0.104872003, -0.200908989, -0.177172840, 0.050135516, -0.140382618, -0.151632637, -0.302908182, -0.014280371, 0.450671107, 0.143694386, -0.159401610, 0.066724256, -0.026534222, -0.070430584, 0.135647580, 0.167352214, -0.078677788, -0.005712656, -0.114101753, -0.007724870, 0.262439877, -0.055149335, -0.065244630, 0.189322218, -0.035380557, 0.112104759, 0.045540042, 0.018787019, -0.098893449, 0.035248782, -0.141057059, -0.091526121, 0.028208766, -0.032848842, 0.030415254, 0.092188813, -0.187351182, 0.057090964, -0.067960620, 0.005717815, -0.006792140, -0.015922593, -0.124947190, 0.000379426, 0.164355934, -0.220041797, 0.216748402, 0.196930081, 0.103509530, 0.100866720, 0.142408788, 0.040827628, 0.000765807, -0.017310528, -0.198024035, -0.069140635, 0.038564909, 0.016080089, 0.085440300, -0.006690328
};

float student_2_0[SIZE] = {
	-0.07208370, 0.07983781, 0.07147270, -0.01360504, -0.06774256, -0.13537227, -0.01750598, -0.09073196, 0.05497033, -0.05037206, 0.23540418, -0.11736005, -0.23117997, -0.05902240, -0.03119455, 0.15223901, -0.11139400, -0.00585924, -0.10548541, -0.01211524, 0.07915746, 0.06613345, 0.08911303, -0.00102657, 0.01593081, -0.37907580, -0.10330607, -0.05482818, 0.05004947, 0.00690339, -0.03590534, 0.08558324, -0.10770932, -0.11822878, 0.07212281, 0.06659395, -0.09733307, -0.04703084, 0.21487296, 0.00332676, -0.17144118, 0.01387705, 0.05225359, 0.24909738, 0.19586447, 0.08365937, 0.05514712, -0.10457313, 0.08820726, -0.19711672, 0.02506794, 0.13274205, 0.08794380, 0.05753503, 0.13124005, -0.05630565, 0.04619022, 0.10201949, -0.12407478, -0.00182640, 0.09795156, -0.04610058, 0.02212590, -0.08120097, 0.19386153, 0.00742685, -0.09308074, -0.07679646, 0.12613510, -0.14033619, -0.08912295, 0.05067704, -0.14483243, -0.14321582, -0.29057258, 0.03047054, 0.37905517, 0.10643579, -0.12828277, 0.00967532, -0.01108540, -0.03460674, 0.14806870, 0.06085889, -0.06039574, -0.04050476, -0.08776933, -0.03152921, 0.19629128, -0.10566644, -0.06261583, 0.17513862, -0.00350511, 0.07603548, 0.04243236, -0.01073614, -0.04975624, 0.00271615, -0.15558687, 0.00995776, 0.07258380, -0.13224432, -0.01801097, 0.08913484, -0.14599384, 0.06561743, -0.03240491, 0.00869741, 0.02023277, 0.00121038, -0.15548772, -0.02801952, 0.12594537, -0.16018392, 0.20704484, 0.18935768, 0.01654653, 0.06287152, 0.10816972, 0.05667374, -0.00805096, 0.00199700, -0.13378651, -0.11088085, 0.10220578, 0.06766332, 0.04479255, -0.01065464
};

float student_2_1[SIZE] = {
	-0.05684885, 0.06685047, 0.03733696, -0.04128755, -0.07697311, -0.06426467, -0.05102938, -0.07587511, 0.08045698, -0.10489555, 0.25765434, -0.07332502, -0.20493139, -0.06294290, -0.05477102, 0.17115486, -0.17058371, -0.02785574, -0.07794818, 0.01003303, 0.08930015, 0.02746038, 0.03535274, -0.00039430, -0.00554623, -0.34943977, -0.11886229, -0.07859161, 0.00564642, -0.01411609, -0.00883428, 0.08318371, -0.08169154, -0.07352263, 0.05184665, 0.04473198, -0.06212711, -0.05646646, 0.20256786, -0.04286620, -0.17135151, -0.00175385, 0.06056983, 0.22759607, 0.18173446, 0.08055146, 0.03921402, -0.10379894, 0.09513867, -0.22838391, 0.04427847, 0.12065725, 0.04592329, 0.09388664, 0.06443220, -0.10768688, 0.05744220, 0.13590743, -0.12596436, -0.00713938, 0.04965511, -0.06865798, 0.01868613, -0.06200247, 0.23705070, 0.07622403, -0.11362714, -0.14239438, 0.13008343, -0.13498877, -0.12064484, 0.02399464, -0.19321048, -0.16989189, -0.32458314, 0.02358329, 0.38669616, 0.14953379, -0.10070341, 0.04083382, -0.01982453, -0.03639423, 0.12702785, 0.11698172, -0.04381832, -0.03157293, -0.05793926, 0.00821187, 0.19526425, -0.08713365, -0.09374043, 0.19624554, -0.02918864, 0.10020587, 0.00903324, -0.01872170, -0.00124292, 0.02038398, -0.15456639, 0.01525868, 0.06908448, -0.04852691, -0.00613520, 0.14050794, -0.13282116, 0.08080183, -0.04881131, 0.04699848, 0.01300587, -0.01430498, -0.13393545, -0.00203812, 0.15050222, -0.15534361, 0.21401003, 0.18600711, 0.10375483, 0.08849408, 0.15131110, 0.03630611, 0.01983692, -0.04193228, -0.23807968, -0.02878676, 0.11819451, 0.04304270, 0.06689727, 0.01486682
};

float student_dkl_0[SIZE] = {
	-0.109323047, 0.023591530, 0.041716479, -0.061327972, -0.110266462, -0.044502132, -0.069776967, -0.161369354, 0.159151539, -0.131357566, 0.192348808, -0.073392287, -0.169343665, -0.056603368, -0.095203921, 0.214617580, -0.178450361, -0.111413106, -0.062727481, 0.017076639, 0.020836171, 0.020829311, 0.000583230, 0.028382150, -0.140618786, -0.318585724, -0.115174592, -0.080884397, -0.035312001, -0.041226260, -0.083814047, 0.055582460, -0.138353869, -0.071435027, 0.022695551, 0.098142408, -0.011405850, -0.073663831, 0.135116354, 0.034082800, -0.251049191, 0.030015670, 0.094577327, 0.233112425, 0.197537482, 0.008954180, 0.010727170, -0.165583640, 0.155116409, -0.184945300, -0.057514880, 0.072377980, 0.048420761, 0.053835861, 0.022808541, -0.101606794, 0.053984448, 0.162847534, -0.155766174, 0.045868739, 0.106032752, -0.053676739, -0.042160131, -0.099933110, 0.195763364, 0.102208853, -0.122157589, -0.158653542, 0.116760850, -0.158978507, -0.113099366, 0.024905849, -0.135441810, -0.214520037, -0.349513978, -0.058253761, 0.374071717, 0.150372103, -0.197099850, 0.013900570, -0.001151690, 0.009521890, 0.150798604, 0.145520210, -0.013994160, 0.046713188, -0.071973622, -0.046120301, 0.255952805, -0.017593861, 0.006325920, 0.199692950, -0.004753730, 0.086717717, 0.009946860, 0.031277310, -0.106250852, 0.023555210, -0.179389372, -0.019528151, 0.020770291, -0.025598099, 0.027288981, 0.111041456, -0.131877765, 0.176420122, 0.003107710, 0.028325530, 0.008473130, -0.014791530, -0.068973318, 0.008686580, 0.174328983, -0.153571948, 0.160585314, 0.192617431, 0.095014207, 0.091224447, 0.142920643, 0.041536231, -0.080029629, 0.047594432, -0.220976427, -0.019488011, 0.070559308, -0.116933778, 0.120215811, 0.000509680
};

float student_dkl_1[SIZE] = {
	-0.152022988, 0.103895292, 0.102671407, -0.078516193, -0.063772239, -0.027836988, -0.066067517, -0.147789672, 0.160193846, -0.151138946, 0.203622028, -0.063535944, -0.174630806, -0.037314314, -0.046970312, 0.180736125, -0.204674557, -0.115560099, -0.073399037, -0.044504121, -0.009162617, 0.005858424, 0.053732738, 0.010039726, -0.083082311, -0.347382337, -0.095931321, -0.067874782, 0.027617898, 0.021972470, -0.063542888, -0.002579812, -0.197877511, -0.030084062, -0.023542382, 0.041319683, -0.021026015, -0.056213431, 0.178869084, -0.049317475, -0.254869372, 0.007454434, 0.086863235, 0.183740079, 0.204548746, 0.066846617, -0.000160312, -0.157979354, 0.133310616, -0.163947538, 0.030124759, 0.115698971, 0.069376908, -0.005825443, 0.039025340, -0.097187474, 0.025547482, 0.150538296, -0.170868397, -0.002767057, 0.108266518, -0.033783983, 0.011320848, -0.087844975, 0.249392539, 0.154502273, -0.100905105, -0.168494374, 0.134207860, -0.176045150, -0.046927966, 0.082506731, -0.098440520, -0.194908649, -0.332216650, -0.034507334, 0.367280960, 0.165221721, -0.104441382, 0.024992160, -0.040692125, -0.038314167, 0.157750532, 0.150102571, -0.119878456, 0.034843761, -0.060131777, -0.023532109, 0.255204350, 0.017469376, -0.058907833, 0.190324113, -0.000506276, 0.041820332, -0.031990319, -0.002428275, -0.102565028, -0.001332768, -0.180509359, -0.023664519, -0.033035036, 0.039251838, -0.001276983, 0.126458585, -0.157359883, 0.110284172, -0.038477205, 0.000002253, -0.029406955, -0.019305440, -0.031693041, -0.027038466, 0.118084297, -0.181177333, 0.114628591, 0.142692953, 0.069364697, 0.124237500, 0.139051944, 0.039064065, -0.032389887, 0.001377810, -0.222199470, -0.008575392, 0.131262988, -0.101295255, 0.214925051, 0.034320217
};

float student_dkl_2[SIZE] = {
	-0.108426072, 0.035143718, 0.015700832, -0.131036744, -0.128725827, -0.016761411, -0.041665658, -0.152716309, 0.167194948, -0.178367883, 0.178242713, -0.088676974, -0.159325808, -0.054005481, -0.091715127, 0.193209544, -0.222998932, -0.133234546, -0.014988874, 0.010257163, 0.049137179, 0.020940699, -0.019443443, 0.045112096, -0.134462118, -0.319106549, -0.119580626, -0.048252925, 0.000410864, -0.050091382, -0.040219694, 0.038081761, -0.173331887, -0.064295329, -0.007949571, 0.134567738, -0.039162051, -0.099108823, 0.137792766, 0.033364136, -0.232588366, 0.044550158, 0.073145255, 0.218339399, 0.175357416, 0.018108044, 0.022297051, -0.146026731, 0.161072165, -0.144159988, -0.056143470, 0.062235512, 0.091445491, 0.024194036, 0.004572618, -0.102346525, 0.058116861, 0.144596353, -0.168871164, 0.039431576, 0.115548089, -0.098332189, 0.018137634, -0.086725608, 0.169975936, 0.054411899, -0.079525456, -0.201119900, 0.155476302, -0.168851480, -0.122848012, 0.044207204, -0.092573740, -0.182318747, -0.322331727, -0.045077354, 0.348252535, 0.167039305, -0.121722057, 0.042596102, 0.009849658, -0.001034911, 0.128951520, 0.149632484, -0.019759402, 0.044023342, -0.103702858, -0.030055426, 0.248910159, -0.011452732, -0.035847154, 0.163095161, -0.009901894, 0.088043258, 0.023252249, -0.000332734, -0.138349682, 0.083110988, -0.121079966, 0.003497774, 0.012391218, -0.053781692, 0.025295734, 0.128445223, -0.112787560, 0.195129275, -0.060300186, 0.010075075, -0.037681259, -0.002257057, -0.091613859, 0.026747752, 0.156428769, -0.189651743, 0.144405484, 0.193207040, 0.070122726, 0.120644167, 0.165978089, 0.053515326, -0.053939920, 0.042514052, -0.249013752, -0.055199441, 0.059599973, -0.101999864, 0.186090305, 0.024721049
};

std::bitset<128 * 640> a_bit;
std::bitset<128 * 640> b_bit;

float Distance(float a[], float b[]) {
	float a_0[128];
	float b_0[128];
	
	int d = 0;
	double d_0 = 0;

	transformation1(Matrix, a, a_0);
	transformation1(Matrix, b, b_0);

	transformation2(pos_x, pos_y, q, a_0);
	transformation2(pos_x, pos_y, q, b_0);

	binaryzation(a_0, a_bit);
	binaryzation(b_0, b_bit);

	get_Hamming_Distance(a_bit, b_bit, d);

	d_0 = pow(d, 0.5) / 640;
	

	return d_0;
}

int main() {
	int i = 0;
	std::cin >> i;
	float test[128];

	srand(time(NULL));
	
	while (i > -1) {
		switch (i) {
			//0号，测试模型调用是否正确
		case 0:
			call_model(test);

			std::cout << "\nvector------------------" << std::endl;

			for (i = 0; i != 128; i++) {
				std::cout << test[i] << std::endl;
			}
			break;

			//其他几个情况，测试算法误差
		case 1:
			for (i = 0; i != 3; i++) {
				std::cout << std::endl;
				std::cout << "丁凯乐和他自己（距离越小越相似）" << std::endl;
				std::cout << "(student_dkl_0, student_dkl_2) = " << Euclidean_Distance(student_dkl_0, student_dkl_2) << std::endl;
				std::cout << "(student_dkl_0, student_dkl_2) = " << Distance(student_dkl_0, student_dkl_2) << std::endl;
			}

			break;
		case 2:
			for (i = 0; i != 3; i++) {
				std::cout << std::endl;
				std::cout << "郑浩然和他自己（距离越小越相似）" << std::endl;
				std::cout << "(stu_1, stu_2) = " << Euclidean_Distance(stu_1, stu_2) << std::endl;
				std::cout << "(stu_1, stu_2) = " << Distance(stu_1, stu_2) << std::endl;
			}
			
			break;
		case 3:
			for (i = 0; i != 3; i++) {
				std::cout << std::endl;
				std::cout << "路人乙和他自己（距离越小越相似）" << std::endl;
				std::cout << "(stu_2_0, stu_2_1) = " << Euclidean_Distance(student_2_0, student_2_1) << std::endl;
				std::cout << "(stu_2_0, stu_2_1) = " << Distance(student_2_0, student_2_1) << std::endl;
			}
			
			break;
		case 4:
			for (i = 0; i != 3; i++) {
				std::cout << std::endl;
				std::cout << "路人甲和路人乙（距离越小越相似）" << std::endl;
				std::cout << "(stu_1_0, stu_2_0) = " << Euclidean_Distance(student_1_0, student_2_0) << std::endl;
				std::cout << "(stu_1_0, stu_2_0) = " << Distance(student_1_0, student_2_0) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_1_0, stu_2_1) = " << Euclidean_Distance(student_1_0, student_2_1) << std::endl;
				std::cout << "(stu_1_0, stu_2_1) = " << Distance(student_1_0, student_2_1) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_1_1, stu_2_0) = " << Euclidean_Distance(student_1_1, student_2_0) << std::endl;
				std::cout << "(stu_1_1, stu_2_0) = " << Distance(student_1_1, student_2_0) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_1_1, stu_2_1) = " << Euclidean_Distance(student_1_1, student_2_1) << std::endl;
				std::cout << "(stu_1_1, stu_2_1) = " << Distance(student_1_1, student_2_1) << std::endl;
				std::cout << std::endl;
			}

			break;
		case 5:
			for (i = 0; i != 3; i++) {
				std::cout << std::endl;
				std::cout << "郑浩然和路人甲（距离越小越相似）" << std::endl;
				std::cout << "(stu_1, stu_1_0) = " << Euclidean_Distance(stu_1, student_1_0) << std::endl;
				std::cout << "(stu_1, stu_1_0) = " << Distance(stu_1, student_1_0) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_1, stu_1_1) = " << Euclidean_Distance(stu_1, student_1_1) << std::endl;
				std::cout << "(stu_1, stu_1_1) = " << Distance(stu_1, student_1_1) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_2, stu_1_0) = " << Euclidean_Distance(stu_2, student_1_0) << std::endl;
				std::cout << "(stu_2, stu_1_0) = " << Distance(stu_2, student_1_0) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_2, stu_1_1) = " << Euclidean_Distance(stu_2, student_1_1) << std::endl;
				std::cout << "(stu_2, stu_1_1) = " << Distance(stu_2, student_1_1) << std::endl;
				std::cout << std::endl;
			}

			break;
		case 6:
			for (i = 0; i != 3; i++) {
				std::cout << std::endl;
				std::cout << "郑浩然和路人乙（距离越小越相似）" << std::endl;
				std::cout << "(stu_1, stu_2_0) = " << Euclidean_Distance(stu_1, student_2_0) << std::endl;
				std::cout << "(stu_1, stu_2_0) = " << Distance(stu_1, student_2_0) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_1, stu_2_1) = " << Euclidean_Distance(stu_1, student_2_1) << std::endl;
				std::cout << "(stu_1, stu_2_1) = " << Distance(stu_1, student_2_1) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_2, stu_2_0) = " << Euclidean_Distance(stu_2, student_2_0) << std::endl;
				std::cout << "(stu_2, stu_2_0) = " << Distance(stu_2, student_2_0) << std::endl;
				std::cout << std::endl;
				std::cout << "(stu_2, stu_2_1) = " << Euclidean_Distance(stu_2, student_2_1) << std::endl;
				std::cout << "(stu_2, stu_2_1) = " << Distance(stu_2, student_2_1) << std::endl;
				std::cout << std::endl;
			}

			break;
		}

		std::cin >> i;
	}
	

	return 0;
}
