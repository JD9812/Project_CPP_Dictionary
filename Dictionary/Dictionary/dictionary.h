#ifndef JD_DICTIONARY_H
#define JD_DICTIONARY_H

#include <string>
#include <fstream>
#include <iostream>

namespace JD {

	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};

	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};

	class Dictionary {

		Word* m_words{};
		size_t m_size{};

		static bool m_show_all;
		static bool m_verbose;

	public:
		Dictionary() = default;
		Dictionary(const char* fileName);

		Dictionary(const Dictionary& other);
		Dictionary& operator=(const Dictionary& other);

		Dictionary(Dictionary&& other);
		Dictionary& operator=(Dictionary&& other);

		~Dictionary();

		void stripCR(std::string& s);

		PartOfSpeech changeSpeech(const std::string& s);

		void searchWord(const char* word);

	};
}


#endif