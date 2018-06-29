// Author: Sean Davis

#include "CheckerRunner.h"
#include "checker.h"
#include "QuadraticProbing.cpp"
Checker::Checker(const DictionaryWord *words, int numWords):dict(NULL,300997)
{
	

	
	for (int i = 0; i < NUM_WORDS; i++)
	{
		char * b = new char[34];
		strcpy(b, words[i].word);

		dict.insert(b);
	}
	//factor[i] = (37^i)%300997
	//the commented out fragment was used to get what goes in to factor.
	/*factor[0] = 1;
	for (int i = 1; i < 34; i++)
	{

		k *= 37;
		k %= 300997;
		factor[i] = k;
	}
	for (int i = 0; i < 34; i++)
	{
		cout << "factor[" << i << "]=" << factor[i] << ";" << endl;
	}*/
	factor[0] = 1;
	factor[1] = 37;
	factor[2] = 1369;
	factor[3] = 50653;
	factor[4] = 68179;
	factor[5] = 114647;
	factor[6] = 27981;
	factor[7] = 132306;
	factor[8] = 79370;
	factor[9] = 227717;
	factor[10] = 298610;
	factor[11] = 212678;
	factor[12] = 43164;
	factor[13] = 92083;
	factor[14] = 96104;
	factor[15] = 244881;
	factor[16] = 30687;
	factor[17] = 232428;
	factor[18] = 171920;
	factor[19] = 40103;
	factor[20] = 279823;
	factor[21] = 119553;
	factor[22] = 209503;
	factor[23] = 226686;
	factor[24] = 260463;
	factor[25] = 5227;
	factor[26] = 193399;
	factor[27] = 232832;
	factor[28] = 186868;
	factor[29] = 292182;
	factor[30] = 275839;
	factor[31] = 273142;
	factor[32] = 173353;
	factor[33] = 93124;



} // Checker()



void Checker::findWord(const char *word, char matchingWords[100][MAX_LENGTH + 1],
  int *count)
{
	int length = strlen(word);
	int hashi = dict.hash(word,300997);
	strcpy(matchingWords[0],word);
	
	if (dict.find(matchingWords[0]))
	{
		*count = 1;
	}
	else
	{
		int l = 0;//letter position
		int fact = factor[length - l - 1];
		int k = 0;

		int itr;
		for (; word[l]; l++)//through every letter in word
		{
			//the following 4 lines determine the first integer to be tested.
			fact = factor[length - l - 1];
			itr = hashi + 300997 * 26;
			itr -= (word[l] - 97)* fact;
			itr %= 300997;
			for (int i = 97; itr != hashi; i++)//through every letter in alphabet less than word
			{
				matchingWords[k][l] = i;

				if (dict.isActive(itr))
				{
					int pos = itr;
					int col = 0;
					while (dict.isActive(pos) && strcmp(matchingWords[k], dict.array[pos]))
					{
						pos += 2 * col + 1;
						col++;
						if (pos >= 300997)
						{
							pos -= 300997;
						}

					}
					if (dict.isActive(pos) && !strcmp(matchingWords[k], dict.array[pos]))
					{
						k++;
						strcpy(matchingWords[k], word);
					}
				}
				itr += fact;
				if (itr >= 300997)
				{
					itr -= 300997;
				}

			}
			strcpy(matchingWords[k], word);

		}
		for (int p = l - 1; p >= 0; p--)//backwards through word
		{
			fact = factor[length - p - 1];
			itr = hashi + fact;
			if (itr >= 300997)
			{
				itr -= 300997;
			}
			for (int i = word[p] + 1; i < 'z' + 1; i++)//through every letter in alphabet
			{

				matchingWords[k][p] = i;

				if (dict.isActive(itr))
				{
					int pos = itr;
					int col = 0;
					while (dict.isActive(pos) && strcmp(matchingWords[k], dict.array[pos]))
					{

						pos += 2 * col + 1;
						col++;
						if (pos >= 300997)
						{
							pos -= 300997;
						}

					}
					if (dict.isActive(pos) && !strcmp(matchingWords[k], dict.array[pos]))
					{
						k++;
						strcpy(matchingWords[k], word);
					}
				}
				itr += fact;
				if (itr >= 300997)
				{
					itr -= 300997;
				}

			}
			strcpy(matchingWords[k], word);
		}
		*count = k;

		/*if (!strcmp(word, "astidistra"))
		{

			cout << dict.hash("astidistra",300997) <<endl;
			cout << dict.hash("abtidistra", 300997) <<endl;
			int fact = factor[length - 2];
			int itr = dict.hash(word, 300997) + 26 * 300997;
			itr -= (word[1] - 97)* fact;
			itr += fact;
			itr %= 300997;
			cout << itr << endl;
			

		}
		
		*count = 0;
		int k = 0;//matchingwords index
		int l = 0;
		for (strcpy(matchingWords[0], word); word[l]; l++)//through every letter in word
		{
			for (int i = 97;i < word[l]; i++)//through every letter in alphabet less than word
			{
				
				matchingWords[k][l] = i;
				if (dict.find(matchingWords[k]))
				{
					k++;
					strcpy(matchingWords[k], word);
				}

			}
			strcpy(matchingWords[k], word);

		}
		for (int p = l - 1; p >= 0; p--)//backwards through word
		{
			for (int i = word[p] + 1; i < 'z' + 1; i++)//through every letter in alphabet
			{

				matchingWords[k][p] = i;
				if (dict.find(matchingWords[k]))
				{
					k++;
					strcpy(matchingWords[k], word);
				}

			}
			strcpy(matchingWords[k], word);
		}
		*count = k;*/
	
		

	}


}


