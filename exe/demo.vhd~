----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:02:07 05/02/2013 
-- Design Name: 
-- Module Name:    ImageMemoryManager - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.all;
--use IEEE.std_logic_arith;
use IEEE.std_logic_unsigned.All;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ImageMemoryManager is
  generic (
    wSize     :integer  := 9;
    hSize     :integer  := 9;
	 Size     :integer  := 9;
    imgWidth  : integer := 512;         -- Largeur de l'image
    imgHeight : integer := 512);        -- Hauteur de l'image
  
  port (Clk             : in    std_logic;
        PxClk           : in    std_logic;
        rW              : in    std_logic;     --      0 --> read / 1 --> WRITE
        Col             : in    std_logic_vector (wSize-1 downto 0);
        Lig             : in    std_logic_vector (hSize-1 downto 0);
        En              : in    std_logic;
        StatusInner   	: in   std_logic;
        UpLeftCorner   	: in   std_logic;	 
        FirstLine    	: in   std_logic;
        FirstRow 			: in   std_logic;
        LastRow	      : in   std_logic;
        LastPixel 		: in   std_logic;        
        Label_e1        : out   std_logic_vector (Size-1 downto 0);
        Label_e2        : out   std_logic_vector (Size-1 downto 0);
        Label_e3        : out   std_logic_vector (Size-1 downto 0);
        Label_e4        : out   std_logic_vector (Size-1 downto 0);
        Label_New       : in    std_logic_vector (Size-1 downto 0);
		  FirstPass    	: in   std_logic
		  );
end ImageMemoryManager;


architecture Behavioral of ImageMemoryManager is
  
  type MemLabel is array (0 to imgWidth-1,0 to imgHeight-1) of std_logic_vector(9 downto 0);  
  signal ImgLabel : MemLabel := ((others=> (others=>"0000000000")));
  signal iH  : integer := 0;
  signal iV  : integer := 0;
begin

  -- purpose: Gestion de la mémoire
  -- type   : combinational
  -- inputs : CLK,rw
  -- outputs: Label_e1/e2/e3/e4
  
  manager : process (CLK,Col,Lig) is
  begin
    iV <= conv_integer(Col);
    iH <= conv_integer(Lig);
    if (CLK'event and CLK = '1') then		
	 if FirstPass ='1' then     -- Mode ecriture   		 
      if rW='0' then     -- Mode ecriture   		 
        if StatusInner='1' then   	-- Si on est sur aucun bord 
          Label_e1 <= ImgLabel(iH-1,iV-1);
          Label_e2 <= ImgLabel(iH-1,iV  );
          Label_e3 <= ImgLabel(iH-1,iV+1);
          Label_e4 <= ImgLabel(iH  ,iV-1);          
		  elsif FirstLine='1' then   	-- Si on est sur aucun bord 
				Label_e1 <= "ZZZZZZZZZZ";
				Label_e2 <= "ZZZZZZZZZZ";
				Label_e3 <= "ZZZZZZZZZZ";				
				Label_e4 <= ImgLabel(iH  ,iV-1);					                       			
		  elsif FirstRow='1' 		then   	 	
		    Label_e1 <= "ZZZZZZZZZZ";
			 Label_e2 <= ImgLabel(iH-1,iV  );
          Label_e3 <= ImgLabel(iH-1,iV+1);
			 Label_e4 <= "ZZZZZZZZZZ";          
		  elsif LastRow='1' 		then 
			 Label_e3 <= "ZZZZZZZZZZ";		  
			 Label_e1 <= ImgLabel(iH-1,iV-1);
          Label_e2 <= ImgLabel(iH-1,iV  );          
          Label_e4 <= ImgLabel(iH  ,iV-1);          
        end if;		 
      else 					 -- Mode Lecture
        if StatusInner='1' then   	-- Si on est sur aucun bord          
          if (ImgLabel(iH-1,iV-1) /= "0000000000") then  ImgLabel(iH-1,iV-1) <= Label_New; end if;
          if (ImgLabel(iH-1,iV  ) /= "0000000000") then  ImgLabel(iH-1,iV  ) <= Label_New; end if;
          if (ImgLabel(iH-1,iV+1) /= "0000000000") then  ImgLabel(iH-1,iV+1) <= Label_New; end if;
          if (ImgLabel(iH  ,iV-1) /= "0000000000") then  ImgLabel(iH  ,iV-1) <= Label_New; end if;
          ImgLabel(iH  ,iV  ) <= Label_New;
		  elsif FirstLine='1' 	then   	
			 if (ImgLabel(iH  ,iV-1) /= "0000000000") then  ImgLabel(iH  ,iV-1) <= Label_New; end if;			
			 ImgLabel(iH  ,iV  ) <= Label_New;
		  elsif UpLeftCorner='1' 	then   	
			 ImgLabel(iH  ,iV  ) <= Label_New;
		  elsif FirstRow='1' 		then   	 	
			 if (ImgLabel(iH-1,iV  ) /= "0000000000") then  ImgLabel(iH-1,iV  ) <= Label_New; end if;
          if (ImgLabel(iH-1,iV+1) /= "0000000000") then  ImgLabel(iH-1,iV+1) <= Label_New; end if;
          ImgLabel(iH  ,iV  ) <= Label_New;						
		  elsif LastRow='1' 		then   	 	
			 if (ImgLabel(iH-1,iV-1) /= "0000000000") then  ImgLabel(iH-1,iV-1) <= Label_New; end if;
          if (ImgLabel(iH-1,iV  ) /= "0000000000") then  ImgLabel(iH-1,iV  ) <= Label_New; end if;
          if (ImgLabel(iH  ,iV-1) /= "0000000000") then  ImgLabel(iH  ,iV-1) <= Label_New; end if;
          ImgLabel(iH  ,iV  ) <= Label_New;						
		end if;
        end if;
		else 
			if rW='0' then    
				Label_e1 <= ImgLabel(iH,iV);
				Label_e2 <= "ZZZZZZZZZZ";
				Label_e3 <= "ZZZZZZZZZZ";
				Label_e4 <= "ZZZZZZZZZZ";
			else 
				ImgLabel(iH  ,iV  ) <= Label_New;			 
				Label_e1 <= ImgLabel(iH,iV);
				Label_e2 <= "ZZZZZZZZZZ";
				Label_e3 <= "ZZZZZZZZZZ";
				Label_e4 <= "ZZZZZZZZZZ";
			end if;
      end if;
    end if;  
  end process manager;
end Behavioral;

