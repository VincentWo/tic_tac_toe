namespace tic_tac_toe
{
	enum class player
	{
		one,
		two,
		none,
		unknown
	};
	class field
	{
		public:
			bool empty() const;
			void fill();
	};
	class game
	{
		public:
			game();
			player winner();

			using size_type = std::size_t;

			field& operator()(size_type x, size_type y);
			const field& operator()(size_type x, size_type y) const;
	};

	std::ostream& operator<<(std::ostream&, const game&);
} 


