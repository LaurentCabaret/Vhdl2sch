library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity RxSystem is
	Port(
		Clk     : in  STD_LOGIC;
		Data    : out STD_LOGIC_VECTOR(7 downto 0);
		DataRdy : out STD_LOGIC;
		Rx      : in  STD_LOGIC
	);
end RxSystem;

architecture Behavioral of RxSystem is
	COMPONENT ClockGenerator
		PORT(
			MAINCLK  : IN  std_logic;
			TRIGGER  : IN  std_logic;
			BAUDRATE : IN  INTEGER;
			CLKOUT   : OUT std_logic
		);
	END COMPONENT;

	COMPONENT RxFSM
		PORT(
			Clk     : in  STD_LOGIC;
			BdClk   : in  STD_LOGIC;
			Data    : out STD_LOGIC_VECTOR(7 downto 0);
			Done    : out STD_LOGIC;
			BdClkEn : out STD_LOGIC;
			ClkMod  : out INTEGER range 0 to 3;
			Rx      : in  STD_LOGIC
		);
	END COMPONENT;

	signal ClkMod   : integer := 3;
	signal BaudRate : integer := 115200;
	signal BdClkEn  : STD_LOGIC;
	signal BdClk    : STD_LOGIC;
begin
	with ClkMod select BaudRate <=
		0 when 0,
		230400 when 1,
		115200 when 2,
		76800 when 3;

	ClkGen : ClockGenerator PORT MAP(
			MAINCLK  => Clk,
			TRIGGER  => BdClkEn,
			BAUDRATE => BaudRate,
			CLKOUT   => BdClk
		);

	RxGenerator : RxFSM PORT MAP(
			Clk     => Clk,
			BdClk   => BdClk,
			Data    => Data,
			Done    => DataRdy,
			BdClkEn => BdClkEn,
			ClkMod  => ClkMod,
			Rx      => Rx
		);

end Behavioral;

