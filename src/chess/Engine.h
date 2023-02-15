#pragma once

#include <vector>
#include <array>
#include <optional>
#include "Common.h"

namespace Chess
{
	class Engine
	{
	public:
		Engine();
		void Reset();
		bool MakeMove(const Move& move);
		std::optional<std::vector<Position>> GetValidMoves(const Position& position);
		const Board& GetBoardState() const
		{
			return m_Board; 
		}
	private:
		void CheckObstacleHorizontally(std::vector<Position>& validMoves, const Position& position, 
			uint8_t length, bool canTake, bool descending);


		std::vector<Position> ValidMovesPawn(const Position& position);
		std::vector<Position> ValidMovesKnight(const Position& position);
		std::vector<Position> ValidMovesBishop(const Position& position);
		std::vector<Position> ValidMovesQueen(const Position& position);
		std::vector<Position> ValidMovesKing(const Position& position);
		std::vector<Position> ValidMovesRook(const Position& position);


		Board m_Board;
	};
}