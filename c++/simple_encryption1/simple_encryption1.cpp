/*
Implement a pseudo-encryption algorithm which given a string S and an integer N concatenates all the odd-indexed characters of S with all the even-indexed characters of S, this process should be repeated N times.

Examples:

encrypt("012345", 1)  =>  "135024"
encrypt("012345", 2)  =>  "135024"  ->  "304152"
encrypt("012345", 3)  =>  "135024"  ->  "304152"  ->  "012345"

encrypt("01234", 1)  =>  "13024"
encrypt("01234", 2)  =>  "13024"  ->  "32104"
encrypt("01234", 3)  =>  "13024"  ->  "32104"  ->  "20314"
Together with the encryption function, you should also implement a decryption function which reverses the process.

If the string S is an empty value or the integer N is not positive, return the first argument without changes.

This kata is part of the Simple Encryption Series:

Simple Encryption #1 - Alternating Split
Simple Encryption #2 - Index-Difference
Simple Encryption #3 - Turn The Bits Around
Simple Encryption #4 - Qwerty
Have fun coding it and please don't forget to vote and rank this kata! :-)
*/

#include <iostream>
#include <string>

using namespace std;

std::string encrypt(std::string text, int n);
std::string decrypt(std::string etext, int n);

std::string generateRandomString()
{
    std::string randomString;

    int randomStringSize = rand()%71 + 1;

    for(int i = 0; i < randomStringSize; i++)
    {
        randomString.append(1, rand()%26 + 65);
    }

    return randomString;
};

Describe(Tests) {
    It(EncryptExmapleTests) {
        Assert::That(encrypt("This is a test!", 0), Equals("This is a test!"));
        Assert::That(encrypt("This is a test!", 1), Equals("hsi  etTi sats!"));
        Assert::That(encrypt("This is a test!", 2), Equals("s eT ashi tist!"));
        Assert::That(encrypt("This is a test!", 3), Equals(" Tah itse sits!"));
        Assert::That(encrypt("This is a test!", 4), Equals("This is a test!"));
        Assert::That(encrypt("This is a test!", -1), Equals("This is a test!"));
        Assert::That(encrypt("This kata is very interesting!", 1), Equals("hskt svr neetn!Ti aai eyitrsig"));
    }

    It(DecryptExmapleTests)
    {
        Assert::That(decrypt("This is a test!", 0), Equals("This is a test!"));
        Assert::That(decrypt("hsi  etTi sats!", 1), Equals("This is a test!"));
        Assert::That(decrypt("s eT ashi tist!", 2), Equals("This is a test!"));
        Assert::That(decrypt(" Tah itse sits!", 3), Equals("This is a test!"));
        Assert::That(decrypt("This is a test!", 4), Equals("This is a test!"));
        Assert::That(decrypt("This is a test!", -1), Equals("This is a test!"));
        Assert::That(decrypt("hskt svr neetn!Ti aai eyitrsig", 1), Equals("This kata is very interesting!"));
    }

    It(EmptyExmapleTests)
    {
        Assert::That(encrypt("", 0), Equals(""));
        Assert::That(encrypt("", 3), Equals(""));
        Assert::That(decrypt("", 0), Equals(""));
        Assert::That(decrypt("", 3), Equals(""));
    }

    It(EncrypDecryptTest)
    {
        Assert::That(decrypt(encrypt("Kobayashi-Maru-Test", 10), 10), Equals("Kobayashi-Maru-Test"));
    }

    It(RandomTests)
    {
        std::function<std::string (std::string, int)> solutionEncrypt = [](std::string text, int n)
        {
            int textLength = text.size();

            if (textLength == 0 || n <= 0)
            {
                return text;
            }

            for(int i = 0; i < n; i++)
            {
                std::string oddChars;
                std::string evenChars;

                for(int j = 0; j < textLength; j++)
                {
                    if (j%2 == 1)
                    {
                        oddChars.append(1, text[j]);
                    }
                    else
                    {
                        evenChars.append(1, text[j]);
                    }
                }

                text = oddChars + evenChars;
            }

            return text;
        };

        std::function<std::string (std::string, int)> solutionDecrypt = [](std::string text, int n)
        {
            int textLength = text.size();

            if (textLength == 0 || n <= 0)
            {
                return text;
            }

            for(int i = 0; i < n; i++)
            {
                std::string leftPart = text.substr(0, textLength >> 1);
                std:: string rightPart = text.substr(textLength >> 1);

                text = "";

                for(int j = 0; j < textLength; j++)
                {
                    text.append(1, j%2 == 1 ? leftPart[j/2] : rightPart[j/2]);
                }
            }

            return text;
        };

        srand(time(0));
        for(int i = 0; i < 100; i++)
        {
            std::string testString = generateRandomString();
            int testShift = random()%10;

            Assert::That(encrypt(testString, testShift), Equals(solutionEncrypt(testString, testShift)));
            Assert::That(decrypt(testString, testShift), Equals(solutionDecrypt(testString, testShift)));
        }
    }
};


int main(int argc, char *argv[]) {
cout <<  encrypt("This kata is very interesting!", 1) << endl;
cout << decrypt(encrypt("This kata is very interesting!", 1),1)<< endl;
	return 0;
}


std::string encrypt(std::string text, int n){
	if ( n <= 0 or text.empty() ) return text;
	string odd{""}, even{""};
	for ( size_t i{}; i < text.size(); i++) {
		(i % 2) ? odd += text[i] : even += text[i];
	};
	text = odd + even;
	n -= 1;
	return ( n == 0 ) ? text : encrypt(text, n);
}

std::string decrypt(std::string etext, int n) {
	if ( n <= 0 or etext.empty() ) return etext;
	string d{etext};
	for ( size_t i{}; i < etext.size()/2; i++) {
		d[2*i+1] = etext[i];
	};
	for ( size_t i{etext.size()/2}; i < etext.size(); i++) {
		d[ 2*(i - etext.size()/2) ] = etext[i];
	};
	n -= 1;
	return ( n == 0 ) ? d : decrypt(d, n);
}
