class LineIterator {
public:

	using iterator_category = std::input_iterator_tag;
	using value_type = std::string;
	using difference_type = std::ptrdiff_t;
	using pointer = std::string*;
	using reference = std::string&;

	LineIterator() : stream_(nullptr), endOfStream_(true) {}

	explicit LineIterator(std::istream& is) : stream_(&is), endOfStream_(false) {
		++(*this);
	}

	LineIterator& operator++() {
		if (std::getline(*stream_, line_)) {
			endOfStream_ = false;
		}
		else {
			endOfStream_ = true;
		}
		return *this;
	}

	const std::string& operator*() const {
		return line_;
	}

	bool operator!=(const LineIterator& other) const {
		return endOfStream_ != other.endOfStream_;
	}

private:
	std::istream* stream_;
	std::string line_;
	bool endOfStream_;
};