#include <fstream>

using namespace std;

long long sol[13][13][27]=
{{{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{4,6,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{5,10,10,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{6,15,20,15,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{7,21,35,35,21,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{8,28,56,70,56,28,8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{9,36,84,126,126,84,36,9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{10,45,120,210,252,210,120,45,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{11,55,165,330,462,462,330,165,55,11,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{12,66,220,495,792,924,792,495,220,66,12,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{13,78,286,715,1287,1716,1716,1287,715,286,78,13,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
},
{{2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{6,11,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{8,22,24,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{10,37,62,46,12,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{12,56,128,148,80,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{14,79,230,367,314,130,20,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{16,106,376,771,920,610,200,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{18,137,574,1444,2232,2083,1106,295,30,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{20,172,832,2486,4744,5776,4352,1897,420,36,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{22,211,1158,4013,9142,13820,13672,8518,3108,581,42,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{24,254,1560,6157,16336,29618,36568,30086,15792,4900,784,49,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{26,301,2046,9066,27492,58277,86662,89402,62292,27966,7476,1036,56,1,0,0,0,0,0,0,0,0,0,0,0,0},
},
{{3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{6,11,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{9,26,26,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{12,50,86,61,14,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{15,83,211,257,143,35,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{18,125,426,758,696,313,60,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{21,176,758,1809,2415,1748,634,101,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{24,236,1234,3736,6706,7057,4176,1290,180,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{27,305,1881,6944,15862,22462,19298,9624,2588,336,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{30,383,2726,11919,33310,60136,69478,49999,21384,5054,580,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{33,470,3796,19228,63856,141384,208472,201525,123883,46144,9658,1005,39,0,0,0,0,0,0,0,0,0,0,0,0,0},
{36,566,5118,29519,113926,300525,544430,672075,554442,295970,97368,18345,1744,64,0,0,0,0,0,0,0,0,0,0,0,0},
{39,671,6719,43521,191809,589507,1274945,1936101,2040007,1459351,685619,201545,34477,3047,105,0,0,0,0,0,0,0,0,0,0,0},
},
{{4,6,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{8,22,24,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{12,50,86,61,14,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{16,92,232,260,112,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{20,150,530,927,770,275,30,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{24,224,1040,2578,3416,2320,720,81,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{28,314,1824,5965,11218,11964,6890,1960,228,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{32,420,2944,12066,29832,44444,38800,18721,4440,400,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{36,542,4464,22135,68646,134248,163326,119359,49158,10239,870,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{40,680,6448,37678,141648,347734,555112,564233,350584,124258,22152,1521,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{44,834,8960,60457,268494,800548,1606864,2147332,1863270,1006293,315828,51406,3492,81,0,0,0,0,0,0,0,0,0,0,0,0},
{48,1004,12064,92488,475464,1678040,4096656,6887876,7853328,5905296,2800960,780416,112640,6400,0,0,0,0,0,0,0,0,0,0,0,0},
{52,1190,15824,136043,796524,3260724,9437936,19321945,27732224,27399460,18092300,7632067,1917520,255722,14620,289,0,0,0,0,0,0,0,0,0,0},
},
{{5,10,10,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{10,37,62,46,12,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{15,83,211,257,143,35,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{20,150,530,927,770,275,30,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{25,240,1124,2728,3368,1960,440,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{30,355,2130,6987,12632,12160,5710,1141,62,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{35,495,3669,15538,38566,55634,44926,19025,3779,323,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{40,660,5862,30776,98968,196011,235156,164652,63094,12016,940,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{45,850,8832,55703,222351,569436,930596,949646,581502,200782,35468,2829,75,0,0,0,0,0,0,0,0,0,0,0,0,0},
{50,1065,12702,93914,450682,1430347,3006528,4133286,3618840,1932177,588204,92268,6192,144,0,0,0,0,0,0,0,0,0,0,0,0},
{55,1305,17597,149665,843169,3218203,8374653,14769649,17347499,13166577,6164561,1661365,231761,14471,285,0,0,0,0,0,0,0,0,0,0,0},
{60,1570,23642,227837,1479116,6635651,20780300,45379022,68366276,69607517,46371028,19268739,4654440,588951,32450,625,0,0,0,0,0,0,0,0,0,0},
{65,1860,30962,333932,2460912,12741248,46952402,123487521,230482217,301111366,269195224,159255587,59406549,13034624,1516698,80981,1419,0,0,0,0,0,0,0,0,0},
},
{{6,15,20,15,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{12,56,128,148,80,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{18,125,426,758,696,313,60,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{24,224,1040,2578,3416,2320,720,81,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{30,355,2130,6987,12632,12160,5710,1141,62,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{36,520,3896,16428,39680,53744,38368,12944,1600,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{42,721,6580,34902,110768,209428,228382,134981,38626,4571,126,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{48,958,10392,67395,271328,683524,1063264,988459,519056,141382,17064,729,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{54,1231,15544,120133,593612,1905625,3966748,5266455,4321574,2087738,551124,71505,3696,64,0,0,0,0,0,0,0,0,0,0,0,0},
{60,1540,22248,200548,1183032,4664384,12350080,21790084,25126400,18333600,8055840,1977664,237952,10816,0,0,0,0,0,0,0,0,0,0,0,0},
{66,1885,30718,317376,2186700,10297579,33450480,74803899,113819204,115313335,75231452,30093144,6858190,796625,38250,625,0,0,0,0,0,0,0,0,0,0},
{72,2266,41168,480601,3799896,20907590,81041896,221719350,425277400,563379272,503110032,292208377,104748800,21424408,2186496,85264,0,0,0,0,0,0,0,0,0,0},
{78,2683,53814,701575,6276240,39664250,179694776,586430711,1374637480,2291516477,2669866932,2118402061,1102928402,357378674,66662866,6353908,247152,3249,0,0,0,0,0,0,0,0},
},
{{7,21,35,35,21,7,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{14,79,230,367,314,130,20,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{21,176,758,1809,2415,1748,634,101,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{28,314,1824,5965,11218,11964,6890,1960,228,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{35,495,3669,15538,38566,55634,44926,19025,3779,323,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{42,721,6580,34902,110768,209428,228382,134981,38626,4571,126,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{49,994,10894,70792,282248,692320,1022320,867328,389312,81184,5792,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{56,1316,16996,132958,655788,2061782,4093126,4989621,3553564,1367310,248766,18061,254,1,0,0,0,0,0,0,0,0,0,0,0,0},
{63,1687,25223,232947,1390077,5454977,14077897,23558243,24851565,15809357,5675197,1048337,85583,2819,27,0,0,0,0,0,0,0,0,0,0,0},
{70,2107,35912,384563,2716480,12945065,41886808,91538222,132976928,125012527,73084352,25114789,4671722,420822,14664,169,0,0,0,0,0,0,0,0,0,0},
{77,2576,49402,603957,4955409,28002390,110167168,301824689,570942795,733133542,622440628,336499210,109835694,20092014,1840420,73445,903,0,0,0,0,0,0,0,0,0},
{84,3094,66032,909585,8531310,56048374,261508702,869978598,2055749814,3412944737,3908832656,3006675589,1495813212,456627054,79284646,7015300,258324,3249,0,0,0,0,0,0,0,0},
{91,3661,86143,1322328,13991174,105158758,570508350,2248967591,6438476607,13296383377,19554502585,20082528026,14009688180,6389776976,1807033438,294131299,24679645,925687,11075,0,0,0,0,0,0,0},
},
{{8,28,56,70,56,28,8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{16,106,376,771,920,610,200,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{24,236,1234,3736,6706,7057,4176,1290,180,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{32,420,2944,12066,29832,44444,38800,18721,4440,400,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{40,660,5862,30776,98968,196011,235156,164652,63094,12016,940,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{48,958,10392,67395,271328,683524,1063264,988459,519056,141382,17064,729,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{56,1316,16996,132958,655788,2061782,4093126,4989621,3553564,1367310,248766,18061,254,1,0,0,0,0,0,0,0,0,0,0,0,0},
{64,1736,26192,242856,1444928,5599888,14082528,22522960,22057472,12448832,3672448,489536,20224,256,0,0,0,0,0,0,0,0,0,0,0,0},
{72,2220,38556,417858,2960916,13989530,44182482,92248703,124262532,103776834,50558802,13127227,1558290,71075,510,1,0,0,0,0,0,0,0,0,0,0},
{80,2768,54592,681556,5660688,32023616,124364320,330291462,591528880,697010448,520664832,233806420,58438640,7313440,375840,6561,0,0,0,0,0,0,0,0,0,0},
{88,3380,74806,1061530,10175632,67672805,315954112,1037127333,2376934586,3747279670,3970076494,2734318794,1169336678,291717581,38810520,2451526,57624,441,0,0,0,0,0,0,0,0},
{96,4056,99704,1589274,17339864,133309036,732881688,2895968891,8206158904,16528152796,23300266248,22476367582,14377733064,5843411716,1421774016,190326225,12153264,287296,0,0,0,0,0,0,0,0},
{104,4796,129794,2300358,28225280,247263787,1572846328,7321126041,24959885338,62029478986,111227126770,141639752181,125258269840,74623660779,28744703880,6768510786,899194286,60020764,1616076,14641,0,0,0,0,0,0},
},
{{9,36,84,126,126,84,36,9,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{18,137,574,1444,2232,2083,1106,295,30,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{27,305,1881,6944,15862,22462,19298,9624,2588,336,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{36,542,4464,22135,68646,134248,163326,119359,49158,10239,870,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{45,850,8832,55703,222351,569436,930596,949646,581502,200782,35468,2829,75,0,0,0,0,0,0,0,0,0,0,0,0,0},
{54,1231,15544,120133,593612,1905625,3966748,5266455,4321574,2087738,551124,71505,3696,64,0,0,0,0,0,0,0,0,0,0,0,0},
{63,1687,25223,232947,1390077,5454977,14077897,23558243,24851565,15809357,5675197,1048337,85583,2819,27,0,0,0,0,0,0,0,0,0,0,0},
{72,2220,38556,417858,2960916,13989530,44182482,92248703,124262532,103776834,50558802,13127227,1558290,71075,510,1,0,0,0,0,0,0,0,0,0,0},
{81,2832,56296,706048,5865552,33001664,126490352,328097824,565532992,627961728,428329024,167227648,33457664,2928256,71552,512,0,0,0,0,0,0,0,0,0,0},
{90,3525,79260,1137354,10959480,72710360,335321130,1073164151,2356552142,3475892685,3332592930,1980008479,679905504,121989260,9603470,279781,1022,1,0,0,0,0,0,0,0,0},
{99,4299,108169,1755988,19391244,149732612,818872572,3180147398,8721201458,16666050218,21722327726,18721500180,10218170444,3328072052,594594700,52174241,1841603,24323,81,0,0,0,0,0,0,0},
{108,5154,143744,2612467,32677426,289767950,1849940738,8553781117,28608195844,68683516953,116750936886,137669052896,109474423762,56521415078,18007449580,3308290504,318125984,14208609,226372,1156,0,0,0,0,0,0},
{117,6090,186708,3763763,52761491,530688460,3897351194,21075570386,84074083186,246506108820,526608539638,808393049185,874475109905,649331825478,319684750598,99688627973,18512601775,1884177640,92662806,1910105,11305,0,0,0,0,0},
},
{{10,45,120,210,252,210,120,45,10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{20,172,832,2486,4744,5776,4352,1897,420,36,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{30,383,2726,11919,33310,60136,69478,49999,21384,5054,580,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{40,680,6448,37678,141648,347734,555112,564233,350584,124258,22152,1521,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{50,1065,12702,93914,450682,1430347,3006528,4133286,3618840,1932177,588204,92268,6192,144,0,0,0,0,0,0,0,0,0,0,0,0},
{60,1540,22248,200548,1183032,4664384,12350080,21790084,25126400,18333600,8055840,1977664,237952,10816,0,0,0,0,0,0,0,0,0,0,0,0},
{70,2107,35912,384563,2716480,12945065,41886808,91538222,132976928,125012527,73084352,25114789,4671722,420822,14664,169,0,0,0,0,0,0,0,0,0,0},
{80,2768,54592,681556,5660688,32023616,124364320,330291462,591528880,697010448,520664832,233806420,58438640,7313440,375840,6561,0,0,0,0,0,0,0,0,0,0},
{90,3525,79260,1137354,10959480,72710360,335321130,1073164151,2356552142,3475892685,3332592930,1980008479,679905504,121989260,9603470,279781,1022,1,0,0,0,0,0,0,0,0},
{100,4380,110960,1809464,20014112,154215760,837543200,3209594096,8611750848,15915225216,19737569920,15811277504,7744593920,2142857984,295974400,17275136,246784,1024,0,0,0,0,0,0,0,0},
{110,5335,150810,2768799,34840344,309181400,1962377890,8944983091,29171793794,67319578031,107901412520,116867849164,82283854136,35674524336,8813210054,1111004961,58604546,1103531,2046,1,0,0,0,0,0,0},
{120,6390,199800,4092429,58026816,587072600,4307202720,23072943626,90217506800,255838385220,519682957200,742032265114,725352302592,468306827096,190226962208,45517138501,5841992408,356481142,8050104,59049,0,0,0,0,0,0},
{130,7545,258922,5867248,92887252,1060537961,8891008260,55228492707,254834216884,870962005451,2187877952352,3988639521059,5182809236916,4684736656434,2852822268242,1122372460290,269927858350,36901262820,2583822944,82056976,887040,3025,0,0,0,0},
},
{{11,55,165,330,462,462,330,165,55,11,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{22,211,1158,4013,9142,13820,13672,8518,3108,581,42,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{33,470,3796,19228,63856,141384,208472,201525,123883,46144,9658,1005,39,0,0,0,0,0,0,0,0,0,0,0,0,0},
{44,834,8960,60457,268494,800548,1606864,2147332,1863270,1006293,315828,51406,3492,81,0,0,0,0,0,0,0,0,0,0,0,0},
{55,1305,17597,149665,843169,3218203,8374653,14769649,17347499,13166577,6164561,1661365,231761,14471,285,0,0,0,0,0,0,0,0,0,0,0},
{66,1885,30718,317376,2186700,10297579,33450480,74803899,113819204,115313335,75231452,30093144,6858190,796625,38250,625,0,0,0,0,0,0,0,0,0,0},
{77,2576,49402,603957,4955409,28002390,110167168,301824689,570942795,733133542,622440628,336499210,109835694,20092014,1840420,73445,903,0,0,0,0,0,0,0,0,0},
{88,3380,74806,1061530,10175632,67672805,315954112,1037127333,2376934586,3747279670,3970076494,2734318794,1169336678,291717581,38810520,2451526,57624,441,0,0,0,0,0,0,0,0},
{99,4299,108169,1755988,19391244,149732612,818872572,3180147398,8721201458,16666050218,21722327726,18721500180,10218170444,3328072052,594594700,52174241,1841603,24323,81,0,0,0,0,0,0,0},
{110,5335,150810,2768799,34840344,309181400,1962377890,8944983091,29171793794,67319578031,107901412520,116867849164,82283854136,35674524336,8813210054,1111004961,58604546,1103531,2046,1,0,0,0,0,0,0},
{121,6490,204130,4199064,59673360,603563504,4412818240,23460698496,90564534336,251806066272,496911749920,680724011264,627368073216,372407249408,133945551616,26761182208,2590398464,102232576,866816,2048,0,0,0,0,0,0},
{132,7766,269610,6165379,98204106,1123921271,9401554074,57937035651,263299149168,878167467960,2127169321400,3681266754660,4446608838056,3630796636984,1918638461982,618061687881,111471381956,9992992570,355460446,4363261,4094,1,0,0,0,0},
{143,9163,348571,8795029,155802507,2001328271,18990189967,134409972250,711961155670,2816817677710,8268550175806,17803075280026,27652668447638,30291122087934,22706176798254,11192537133109,3440532118411,614264916119,57577642711,2503253537,38934863,210275,243,0,0,0},
},
{{12,66,220,495,792,924,792,495,220,66,12,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{24,254,1560,6157,16336,29618,36568,30086,15792,4900,784,49,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{36,566,5118,29519,113926,300525,544430,672075,554442,295970,97368,18345,1744,64,0,0,0,0,0,0,0,0,0,0,0,0},
{48,1004,12064,92488,475464,1678040,4096656,6887876,7853328,5905296,2800960,780416,112640,6400,0,0,0,0,0,0,0,0,0,0,0,0},
{60,1570,23642,227837,1479116,6635651,20780300,45379022,68366276,69607517,46371028,19268739,4654440,588951,32450,625,0,0,0,0,0,0,0,0,0,0},
{72,2266,41168,480601,3799896,20907590,81041896,221719350,425277400,563379272,503110032,292208377,104748800,21424408,2186496,85264,0,0,0,0,0,0,0,0,0,0},
{84,3094,66032,909585,8531310,56048374,261508702,869978598,2055749814,3412944737,3908832656,3006675589,1495813212,456627054,79284646,7015300,258324,3249,0,0,0,0,0,0,0,0},
{96,4056,99704,1589274,17339864,133309036,732881688,2895968891,8206158904,16528152796,23300266248,22476367582,14377733064,5843411716,1421774016,190326225,12153264,287296,0,0,0,0,0,0,0,0},
{108,5154,143744,2612467,32677426,289767950,1849940738,8553781117,28608195844,68683516953,116750936886,137669052896,109474423762,56521415078,18007449580,3308290504,318125984,14208609,226372,1156,0,0,0,0,0,0},
{120,6390,199800,4092429,58026816,587072600,4307202720,23072943626,90217506800,255838385220,519682957200,742032265114,725352302592,468306827096,190226962208,45517138501,5841992408,356481142,8050104,59049,0,0,0,0,0,0},
{132,7766,269610,6165379,98204106,1123921271,9401554074,57937035651,263299149168,878167467960,2127169321400,3681266754660,4446608838056,3630796636984,1918638461982,618061687881,111471381956,9992992570,355460446,4363261,4094,1,0,0,0,0},
{144,9284,355000,8992684,159698416,2052729728,19447224864,137045115696,720227187456,2814607288320,8114138417152,17029582652416,25527244986880,26621798120192,18641209009664,8351679964416,2239205064704,326954181632,22350518272,601932800,2977792,4096,0,0,0,0},
{156,10946,457886,12763465,251079686,3602124669,38420994612,307903704966,1861843334208,8487961586832,29019134230424,73678922158740,136918473752216,182525471295024,169924042811094,106596745975005,42955197700844,10418884325278,1386659588314,89204078327,2147773810,17292275,8190,1,0,0},
},
{{13,78,286,715,1287,1716,1716,1287,715,286,78,13,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{26,301,2046,9066,27492,58277,86662,89402,62292,27966,7476,1036,56,1,0,0,0,0,0,0,0,0,0,0,0,0},
{39,671,6719,43521,191809,589507,1274945,1936101,2040007,1459351,685619,201545,34477,3047,105,0,0,0,0,0,0,0,0,0,0,0},
{52,1190,15824,136043,796524,3260724,9437936,19321945,27732224,27399460,18092300,7632067,1917520,255722,14620,289,0,0,0,0,0,0,0,0,0,0},
{65,1860,30962,333932,2460912,12741248,46952402,123487521,230482217,301111366,269195224,159255587,59406549,13034624,1516698,80981,1419,0,0,0,0,0,0,0,0,0},
{78,2683,53814,701575,6276240,39664250,179694776,586430711,1374637480,2291516477,2669866932,2118402061,1102928402,357378674,66662866,6353908,247152,3249,0,0,0,0,0,0,0,0},
{91,3661,86143,1322328,13991174,105158758,570508350,2248967591,6438476607,13296383377,19554502585,20082528026,14009688180,6389776976,1807033438,294131299,24679645,925687,11075,0,0,0,0,0,0,0},
{104,4796,129794,2300358,28225280,247263787,1572846328,7321126041,24959885338,62029478986,111227126770,141639752181,125258269840,74623660779,28744703880,6768510786,899194286,60020764,1616076,14641,0,0,0,0,0,0},
{117,6090,186708,3763763,52761491,530688460,3897351194,21075570386,84074083186,246506108820,526608539638,808393049185,874475109905,649331825478,319684750598,99688627973,18512601775,1884177640,92662806,1910105,11305,0,0,0,0,0},
{130,7545,258922,5867248,92887252,1060537961,8891008260,55228492707,254834216884,870962005451,2187877952352,3988639521059,5182809236916,4684736656434,2852822268242,1122372460290,269927858350,36901262820,2583822944,82056976,887040,3025,0,0,0,0},
{143,9163,348571,8795029,155802507,2001328271,18990189967,134409972250,711961155670,2816817677710,8268550175806,17803075280026,27652668447638,30291122087934,22706176798254,11192537133109,3440532118411,614264916119,57577642711,2503253537,38934863,210275,243,0,0,0},
{156,10946,457886,12763465,251079686,3602124669,38420994612,307903704966,1861843334208,8487961586832,29019134230424,73678922158740,136918473752216,182525471295024,169924042811094,106596745975005,42955197700844,10418884325278,1386659588314,89204078327,2147773810,17292275,8190,1,0,0},
{169,12896,589196,18024072,391202680,6229649352,74255991784,670158151296,4603893554496,24088436720256,95639134395520,285933260795648,636101065346560,1035603214682368,1206627264035328,976895157625344,528490972682240,181285801375744,36676598256640,3954823180288,192433799168,3562792960,10434560,8192,0,0},
},
};


void main()
{
	int n,m,k;
	ifstream fin("bishop.in");
	ofstream fout("bishop.out");
	do
	{
		fin>>n>>m>>k;
		if (n==-1) break;
		if (k<=27) fout<<sol[n-1][m-1][k-1]<<endl;
		else fout<<0<<endl;
	} while (1);
	fin.close();
	fout.close();

}