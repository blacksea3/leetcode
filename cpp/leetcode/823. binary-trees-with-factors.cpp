#include "public.h"

//44ms, 97.67%
//dp问题
//给A排序, 然后定义dp[i]:以下标i为root的二叉树数量
//然后更新dp, 首先dp=1, 其次寻找是否有两个比他小的数字乘积为A[i], 若为两不同则dp[i] += 2*dp[x]*dp[y], 若相同则dp[i] += dp[x]*dp[x]

class Solution {
public:
	int numFactoredBinaryTrees(vector<int>& A) {
		vector<long long> dp(A.size());

		dp[0] = 1;

		sort(A.begin(), A.end());

		for (int i = 1; i < A.size(); ++i)
		{
			int left = 0;
			int right = i - 1;
			dp[i] = 1;
			while (left <= right)
			{
				if ((long long)A[left] * A[right] > INT_MAX) right--;
				else if (A[left] * A[right] == A[i])
				{
					if (left != right) dp[i] += 2 * dp[left] * dp[right];
					else dp[i] += dp[left] * dp[right];
					left++;
					right--;
				}
				else if (A[left] * A[right] > A[i]) right--;
				else left++;
			}
		}

		long long res = accumulate(dp.begin(), dp.end(), (long long)0);

		return res % 1000000007;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> A = { 2,4 };
	//cout << s->numFactoredBinaryTrees(A);
	vector<int> A = { 18,3, 6, 2 };
	cout << s->numFactoredBinaryTrees(A);
	//vector<int> A = { 767520,91499520,1336764,41598354,48070400,14676480,51781632,45603480,43200,5640,665,67392000,258876,177553950,281424,838515600,88179840,695705472,53143734,670320,806,647534592,289476000,259616700,538989360,18461520,493722432,372960,49,9013200,1462,160496640,8262,551110560,394740,3455060,9752400,375840,18079200,516,51,57542400,1864800,7215744,1380672,33601920,14403840,20,8536704,58373172,802433016,21471480,1129392,460,413540,2137444,1636800,10880,833,270802,1252800,203040,26,992,70640400,534600,2169132,673505280,11566800,41446080,780,178200,7,26127360,480924900,575769600,146577600,2019600,1008,357283840,159936000,1693120,737095680,90,328230700,53856000,5347056,132192,772390080,47434464,115473600,9319536,19800,62100,198000,26231040,71075520,167400000,78586200,2575872,716636160,399360,46,29760,56627904,57564000,50379840,153125000,319800,475136928,313728,24437760,8526,486205440,4626720,2340576,78975468,3004400,47,3201600,55944000,8370,642600,6300,100352,19440,225330,19906560,3520,16379904,13104,837000000,174960000,623001600,2178560,11664000,17539200,4230,574801920,21930,864000,480664800,4656960,720,96623280,28576800,8337210,146126592,10,110522880,933970752,3,983537280,218268,179625600,114576,656250,847086240,4860,330,655361280,129024480,213440000,105,10546200,12210,3720,3149250,33,109680480,1865920,29568,1456,91264,2700000,192447360,28,304378200,116746344,85225896,722610,13053600,1664832,808790400,96909120,64912800,252,69300,2813580,392,554098272,62775648,900900,2387280,11,46690,51930240,2946240,30427488,1296000,4176,327360,20995200,34992,492602880,5583600,46679328,582120,343656000,21548160,273240,66846720,1870848,629185920,578088000,74840640,493580,2025000,113286600,65790,1014594,1334,886485600,150585600,1104,55573544,340200,761400,42328000,121524,268272000,336,4233600,6,109058400,8491392,527788800,702240,708505600,644744240,77760,1207680,31,135475200,244944000,40924800,123530400,257094000,9622800,226842560,25719120,112,5331312,96,507735360,864230400,44,987033600,8714240,85,25272000,70048800,372552000,20401920,476280000,338348400,10060200,5616,12600,37,7959168,12027960,788256,1034880,852405120,200970,100640,6375,20700,45540,1612806,18480,5167800,1918080,1512,50592,9504000,6109440,47720904,80388,2294,673200,57528,11340000,147052800,230247360,1940400,2980416,105840,763680,264600000,523832400,3264,78732000,22680,10031040,38,142147710,7931040,7603200,777288960,20304,808635,421303680,238392000,48,14,196416000,625,7188480,9535680,3888,2302020,1458240,117028800,19404,49920,34467840,20098044,501600,1350000,21,224640,7244160,208800,11416720,533520,70531776,165267200,13,209119680,16339200,5076,960,118329120,43848,3735200,499685760,6396,437060,447635160,151200,4080,120,526156280,2040,31579200,609120,5959800,35,1025640,228937500,17168580,102750480,297216,6210,769984800,1599360,32640,11664,690,1797120,25,43623360,15,42412500,683860320,40102920,182700,1048320,202368,5287680,2622,16996320,147840,8916480,2141594,825,183283200,115128000,1445220,16524000,7102158,19183500,1050,738720,23310,108864000,972537020,371226240,17884800,94474512,641491200,235544960,28753920,1854840,199920000,2464,17582400,757350,13440,66640,13200,319872,45,466527600,156247476,44198784,249458,496800,7105320,30,7618560,2024640,198042624,550560,30787680,371726250,182564928,152064000,20403240,55480320,415441920,1040520,367080,2,320993280,18060,16,14968800,22291200,118800,117600,6182568,371520,9473760,191147040,55836,65120,21311472,757680,991440,13003200,681807168,94500,590020200,208915200,103783680,395136000,17,300641280,10080,2048,151208640,721677600,28171800,142076480,102236160,115953600,282,1740800,198288000,255494250,74810540,15960,1727530,27744,349920,489600,954600000,120294720,26656,328440,2673528,44915780,1392,23284800,7507200,14850000,67092480,950400,425952,23,6293,28690200,146286000,1522800,590475600,60234240,812036160,305777640,1066,4071600,37684224,816,47250,130,616,60,14283000,671422500,993600,392544,126904320,52026,4546080,53581500,13739040,85260,61289760,163397520,2520,138,713,102060,129254400,233280,956188800,288921600,43545600,939060,879298560,2518960,485222400,9434880,5128200,2071008,10523520,517267296,216720,4263840,705640320,524929944,12792,417530880,169099,22453200,103530240,600880,66816,687063360,1692,163800576,1247400,169136,471458880,26649000,100850400,1527360,234426192,11880,1325184,3861,68080,13226976,135449600,378510,18328320,9720,11408,6528,444426240,23603400,24041472,250240,840,3136,9098112,33024,608860800,197070720,160992,316838340,86935680,361584000,537062400,13340000,1666,714,3207600,414607200,4388580,703296000,4898880,10281600,66166400,774225,429028320,8,10800,99435600,142884000,532980000,35897400,418660704,634016292,36,43,60999680,1560,174155520,7236900,360,9,20457360,25704,332640,1572480,60775680,1084566,21242,877282560,159667200,18823680,213840000,237762000,19,12420,122496192,14674,49338720,187200,245877120,28050,499035600,199920,27165600,130032,11881800,1339200,67860,9977760,540,11152,503884800,498960,4128,5,15218272,12384,14084280,19699680,110735100,301806000,348532800,2728,5644800,2064,24960,1520,263736000,99145200,25515000,91672560,663264000,8586900,96368160,53280,367007760,72783360,35424000,1142400,515040,3150,16037280,4,18,494,761425920,579889800,4252500,13746240,958566400,816083424,8596560,2375,171360,128943360,420,269494680,22,18052776,36691200,21288960,31360,434928,41,64,130713600,623162880,9806850,144,403307520,760872960,57283200,329041440,373626000,8040384,410231680,3572100,472024800,5330,2668000,1716858,33566400,25704000,1800,1707520,190920,36288,303030,1224510,16200,12791520,3294720,4950,2397600,916531200,285418000,1740,3250800,265920480,844074,217600,75984480,170100,9164160,28800,8326668,99840,68211072,3951360,10421208,443573676,1267200,1134,520914240,194016,27,678585600,45460800,289800,923155200,55350000,38880,99993972,13880160,99,113308800,475200,396809280,30437820,399600000,71442000,12474000,104570880,71038240,1944320,142128,899469480,7996800,261870,310500,17205,4144608,23560,14513920,709789500,455112000,51149532,3137280,30240000,15966240,1080000,268531200,102228480,366300,1638,417384000,489888000,29,352235520,129600,61630800,12,82368000,41025600,272,370,272320,181238400,42,6603300,814531200,33881760,6763960,124200,16842240,6201600,91282464,196,276307200,295160840,107678880,256493280,89302500,71850240,291600,7402752,6090,10148160,743040,142560,256,84150000,15315300,258075,245000,200448,9896040,176344128,10495800,999694080,428652000,547181040,317906120,2612288,32,347276160,601201440,6416540,334816020,89804880,30902400,39,152189100,927628800,57507840,97524000,3995136,401289420,591763200,266760,21960960,29955200,791683200,776160,527472000,16074240,16920,595200,67173120,5280,620,68376000,479587500,21735000,525477888,1269504,21600000,334863360,39513600,735540,408064800,310464,114048000,847895040,454896,2160,8145312,24,106720,188770176,99021312,62937000,41400,80,29937600,99163584,412387200,69076800,358092,749700000,15385920,41354,449064000,3654,62,9979200,5362560,16512,714067200,86423040,27410400,555,284342100,21769440,812700,126491904,486,97796160,8412320,155790720,464032800,389999232,131369472,9102240,2679600,4334400,60480,9343152,303061248,5832000,922521600,594762,1278900,349440,6240,5552064,6557760,34986,945584640,211221504,6606720,935813760,40,198660,2960,84123200,156864,203,101594064,6765120,43706,309104640,523169280,25159680,42477120,41650000,125,598,8352,270,763408800,53706240,477459840,2634240,22232560,370828800,798336000,36720,30735360,34 };	
	//cout << s->numFactoredBinaryTrees(A);
	return 0;
}
