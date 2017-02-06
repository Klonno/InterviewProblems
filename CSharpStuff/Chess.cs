using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpStuff
{
    class ChessSpace
    {
        public enum SpaceColor
        {
            Black,
            White
        }

        internal SpaceColor Color { get; set; }

        public ChessSpace(SpaceColor color)
        {
            Color = color;
        }
    }
    class ChessBoard
    {
        const int NumberOfRows = 8;
        const int SpacesPerRow = 8;
 
        private ChessSpace[,] Spaces = new ChessSpace[NumberOfRows, SpacesPerRow];

        public string PlayerName { get; set; }

        public ChessBoard()
        {
            ChessSpace.SpaceColor currentColor = ChessSpace.SpaceColor.Black;

            for (int row = 0; row < NumberOfRows; ++row)
            {
                for (int i = 0; i < SpacesPerRow; ++i)
                {
                    ChessSpace space = new ChessSpace(currentColor);
                    Spaces[row,i] = space;

                    // toggle color for next space
                    ToggleColor(ref currentColor);
                }

                // toggle color for next row
                ToggleColor(ref currentColor);
            }
        }

        private void ToggleColor(ref ChessSpace.SpaceColor color)
        {
            if (color == ChessSpace.SpaceColor.Black)
            {
                color = ChessSpace.SpaceColor.White;
            }
            else
            {
                color = ChessSpace.SpaceColor.Black;
            }
        }
    }
}
