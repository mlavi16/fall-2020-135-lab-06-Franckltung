#include <cmath>
#include "decode.h"
#include "decrypt.h"
#include "funcs.h"

std::string decodeCaesar(std::string coded) {
	std::string candidates[26]; // Candidate decrypted strings
	double score[26] = {0}; // Score of each candidate
	double frequency[] = 
	{	8.2, 1.5, 2.8, 4.3, 13,
		2.2, 2, 6.1, 7, 0.15,
		0.77, 4, 2.4, 6.7, 7.5,
		1.9, 0.095, 6, 6.3, 9.1,
		2.8, 0.98, 2.4, 0.15, 2,
		0.074
	}; // Common frequency of letters from a to z. Source: Wikipedia

	// Try shifts from 0 to 25
	for (int i = 0; i < 26; i++) {
		candidates[i] = decryptCaesar(coded, i);
		std::string& candidate = candidates[i]; // Reference to current candidate
		int candidateCount[26] = {0}; // Count of letters from a to z in the candidate
		double candidateFrequency[26]; // Frequency of letters from a to z in the candidate
		double distanceSquared[26]; // Distance from common frequency of each letter
		
		// Count characters
		for (int i = 0; i < candidate.length(); i++) {
			if (isLowerCase(candidate[i])) {
				candidateCount[candidate[i] - 'a']++;
			}
			else if (isUpperCase(candidate[i])) {
				candidateCount[candidate[i] - 'A']++;
			}
		}
		// Calculate frequency in percent
		for (int i = 0; i < 26; i++) {
			candidateFrequency[i] = (double)candidateCount[i] / candidate.length() * 100;
		}
		// Get distance from each letter squared
		for (int i = 0; i < 26; i++) {
			distanceSquared[i] = pow(candidateFrequency[i] - frequency[i], 2);
		}
		// Score is the sum of all distances squared, you don't have to take the square root if you don't need the actual distance
		for (int distanceIter = 0; distanceIter < 26; distanceIter++) {
			score[i] += distanceSquared[distanceIter];
		}
	}
	
	// Lowest score is the smallest distance
	int	lowestScore = 0; // Assume the first number is the lowest
	for (int i = 1; i < 26; i++) {
		if (score[i] < score[lowestScore]) {
			lowestScore = i;
		}
	}
	return candidates[lowestScore];
}


