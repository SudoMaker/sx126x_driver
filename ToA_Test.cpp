/*
    This file is part of SX126x Portable driver.
    Copyright (C) 2020 ReimuNotMoe

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "SX126x.hpp"

#include <cstdio>
#include <cinttypes>
#include <cassert>

int main() {
	SX126x::ModulationParams_t ModulationParams2;
	ModulationParams2.PacketType = SX126x::PACKET_TYPE_LORA;
	ModulationParams2.Params.LoRa.CodingRate = SX126x::LORA_CR_4_6;
	ModulationParams2.Params.LoRa.Bandwidth = SX126x::LORA_BW_500;
	ModulationParams2.Params.LoRa.SpreadingFactor = SX126x::LORA_SF10;
	ModulationParams2.Params.LoRa.LowDatarateOptimize = 0;

	SX126x::PacketParams_t PacketParams2;
	PacketParams2.PacketType = SX126x::PACKET_TYPE_LORA;
	auto &l = PacketParams2.Params.LoRa;
	l.PayloadLength = 253;
	l.HeaderType = SX126x::LORA_PACKET_FIXED_LENGTH;
	l.PreambleLength = 12;
	l.CrcMode = SX126x::LORA_CRC_ON;
	l.InvertIQ = SX126x::LORA_IQ_NORMAL;

	auto ToA = SX126x::GetTimeOnAir(ModulationParams2, PacketParams2);
	printf("ToA: %" PRIu32 "\n", ToA);

	assert(ToA == 677);

	return 0;
}