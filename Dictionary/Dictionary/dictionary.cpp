#include "dictionary.h"

namespace JD {

	bool m_show_all{};
	bool m_verbose{};

	void Dictionary::stripCR(std::string& s) {
		if (!s.empty() && s.back() == '\r') s.pop_back();
	}

	Dictionary::Dictionary(const char* fileName) {

		m_words = nullptr;
		m_size = 0;

		std::ifstream file(fileName);

		if (file) {

			std::string temp;

			while (std::getline(file, temp)) {
				++m_size;
			}

			m_words = new Word[m_size];

			file.clear();
			file.seekg(0);

			for (size_t i = 0; i < m_size; i++)
			{
				std::getline(file, m_words[i].m_word, ',');
				stripCR(m_words[i].m_word);

				std::getline(file, temp, ',');

				m_words[i].m_pos = changeSpeech(temp);

				std::getline(file, m_words[i].m_definition);

			}
		}

	}

	Dictionary::~Dictionary() {

		delete[] m_words;
		m_words = nullptr;
		m_size = 0;

	}

	Dictionary::Dictionary(const Dictionary& other) {

		m_words = nullptr;
		m_size = other.m_size;

		if (m_size > 0) {
			m_words = new Word[m_size];
			for (size_t i = 0; i < m_size; ++i) {
				m_words[i] = other.m_words[i];
			}
		}

	}

	Dictionary& Dictionary::operator=(const Dictionary& other) {
		if (this != &other) {
			Word* newWords = nullptr;

			if (other.m_size > 0) {
				newWords = new Word[other.m_size];
				for (size_t i = 0; i < other.m_size; ++i) {
					newWords[i] = other.m_words[i];
				}
			}

			delete[] m_words;
			m_words = newWords;
			m_size = other.m_size;
		}
		return *this;
	}

	Dictionary::Dictionary(Dictionary&& other) {
		m_words = other.m_words;
		m_size = other.m_size;

		other.m_words = nullptr;
		other.m_size = 0;
	}

	Dictionary& Dictionary::operator=(Dictionary&& other) {
		if (this != &other) {
			delete[] m_words;

			m_words = other.m_words;
			m_size = other.m_size;

			other.m_words = nullptr;
			other.m_size = 0;
		}
		return *this;
	}

	PartOfSpeech Dictionary::changeSpeech(const std::string& s) {
		if (s == "n.")  return PartOfSpeech::Noun;
		if (s == "n. pl.")  return PartOfSpeech::Noun;
		if (s == "adv.")  return PartOfSpeech::Adverb;
		if (s == "a.")  return PartOfSpeech::Adjective;
		if (s == "v.")  return PartOfSpeech::Verb;
		if (s == "v. i.")  return PartOfSpeech::Verb;
		if (s == "v. t.")  return PartOfSpeech::Verb;
		if (s == "v. t. & i.")  return PartOfSpeech::Verb;
		if (s == "prep.")  return PartOfSpeech::Preposition;
		if (s == "pron.")  return PartOfSpeech::Pronoun;
		if (s == "conj.")  return PartOfSpeech::Conjunction;
		if (s == "interj.")  return PartOfSpeech::Interjection;

		return PartOfSpeech::Unknown;
	}

	void Dictionary::searchWord(const char* word) {

		bool found = false;
		bool first = true;

		for (size_t i = 0; i < m_size; i++)
		{
			if (m_words[i].m_word.compare(word) == 0) {

				if (first)
				{
					std::cout << m_words[i].m_word << " - ";

					if (m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown)
					{
						switch (m_words[i].m_pos) {

						case PartOfSpeech::Noun:
							std::cout << "(noun) ";
							break;

						case PartOfSpeech::Pronoun:
							std::cout << "(pronoun) ";
							break;

						case PartOfSpeech::Adjective:
							std::cout << "(adjective) ";
							break;

						case PartOfSpeech::Adverb:
							std::cout << "(adverb) ";
							break;

						case PartOfSpeech::Verb:
							std::cout << "(verb) ";
							break;

						case PartOfSpeech::Preposition:
							std::cout << "(preposition) ";
							break;

						case PartOfSpeech::Conjunction:
							std::cout << "(conjuction) ";
							break;

						case PartOfSpeech::Interjection:
							std::cout << "(interjection) ";
							break;

						default:
							break;
						}
					}

					std::cout << m_words[i].m_definition << std::endl;

					first = false;

				}
				else if (m_show_all)
				{
					std::cout.width(m_words[i].m_word.length());
					std::cout << "";
					std::cout << " - ";

					if (m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown)
					{
						switch (m_words[i].m_pos) {

						case PartOfSpeech::Noun:
							std::cout << "(noun) ";
							break;

						case PartOfSpeech::Pronoun:
							std::cout << "(pronoun) ";
							break;

						case PartOfSpeech::Adjective:
							std::cout << "(adjective) ";
							break;

						case PartOfSpeech::Adverb:
							std::cout << "(adverb) ";
							break;

						case PartOfSpeech::Verb:
							std::cout << "(verb) ";
							break;

						case PartOfSpeech::Preposition:
							std::cout << "(preposition) ";
							break;

						case PartOfSpeech::Conjunction:
							std::cout << "(conjuction) ";
							break;

						case PartOfSpeech::Interjection:
							std::cout << "(interjection) ";
							break;

						default:
							break;
						}
					}

					std::cout << m_words[i].m_definition << std::endl;
				}
				else
				{
					return;
				}

				found = true;
			}

		}

		if (!found)
		{
			std::cout << "Word '" << word << "' was not found in the dictionary.\n";
		}



	}

}
