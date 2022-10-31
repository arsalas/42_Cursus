-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 29-03-2021 a las 17:30:12
-- Versión del servidor: 10.4.14-MariaDB
-- Versión de PHP: 7.4.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `pac3_daw`
--
CREATE DATABASE IF NOT EXISTS `pac3_daw` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE `pac3_daw`;
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `category`
--

CREATE TABLE `category` (
  `CategoryID` int(11) NOT NULL,
  `Name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `category`
--

INSERT INTO `category` (`CategoryID`, `Name`) VALUES
(1, 'PANTALÓN'),
(2, 'CAMISA'),
(3, 'JERSEY'),
(4, 'CHAQUETA');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `product`
--

CREATE TABLE `product` (
  `ProductID` int(11) NOT NULL,
  `Name` varchar(50) NOT NULL,
  `Cost` decimal(10,2) NOT NULL,
  `Price` decimal(10,2) NOT NULL,
  `CategoryID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `product`
--

INSERT INTO `product` (`ProductID`, `Name`, `Cost`, `Price`, `CategoryID`) VALUES
(1, 'Loop 501 Talla S', '100.00', '125.00', 1),
(2, 'Loop 501 Talla M', '100.00', '125.00', 1),
(3, 'Loop Talla S', '25.00', '30.00', 2),
(4, 'Loop Talla M', '25.00', '30.00', 2),
(5, 'Jersey Rojo Talla S', '100.00', '110.00', 3),
(6, 'Jersey Rojo Talla S', '100.00', '150.00', 3),
(7, 'Jersey Verde Talla S', '100.00', '150.00', 3),
(8, 'Jersey Verde Talla M', '100.00', '150.00', 3),
(9, 'Jersey Rojo Talla M', '100.00', '150.00', 3),
(10, 'Trousers Blue Talla S', '200.00', '225.00', 1),
(11, 'Trousers Blue Talla M', '200.00', '225.00', 1),
(12, 'Trousers Red Talla S', '200.00', '225.00', 1),
(13, 'Trousers Red Talla M', '200.00', '225.00', 1),
(14, 'Trousers Red Talla L', '200.00', '225.00', 1),
(15, 'Trousers Red Talla XL', '200.00', '225.00', 1),
(16, 'Trousers Green Talla S', '200.00', '225.00', 1),
(17, 'Trousers Green Talla M', '200.00', '225.00', 1),
(18, 'Trousers Green Talla L', '200.00', '225.00', 1),
(19, 'Trousers Green Talla XL', '200.00', '225.00', 1),
(20, 'Jacket Green Talla S', '200.00', '225.00', 1),
(21, 'Jacket Green Talla M', '200.00', '225.00', 1),
(22, 'Jacket Green Talla L', '200.00', '225.00', 1),
(23, 'Jacket Green Talla XL', '200.00', '225.00', 1),
(24, 'Jacket Red Talla S', '200.00', '225.00', 1),
(25, 'Jacket Red Talla M', '200.00', '225.00', 1),
(26, 'Jacket Red Talla L', '200.00', '225.00', 1),
(27, 'Jacket Red Talla XL', '200.00', '225.00', 1),
(28, 'Camisa Purple Talla S', '50.00', '75.00', 2),
(29, 'Camisa Purple Talla M', '50.00', '75.00', 2),
(30, 'Camisa Purple Talla L', '50.00', '75.00', 2),
(31, 'Camisa Purple Talla XL', '50.00', '75.00', 2),
(32, 'Camisa Ivory Talla S', '50.00', '75.00', 2),
(33, 'Camisa Ivory Talla M', '50.00', '75.00', 2),
(34, 'Camisa Ivory Talla L', '50.00', '75.00', 2),
(35, 'Camisa Ivory Talla XL', '50.00', '75.00', 2),
(36, 'Camisa Iris Talla S', '50.00', '75.00', 2),
(37, 'Camisa Iris Talla M', '50.00', '75.00', 2),
(38, 'Camisa Iris Talla L', '50.00', '75.00', 2),
(39, 'Camisa Iris Talla XL', '50.00', '75.00', 2),
(40, 'Camisa Indigo Talla S', '50.00', '75.00', 2),
(41, 'Camisa Indigo Talla M', '50.00', '75.00', 2),
(42, 'Camisa Indigo Talla L', '50.00', '75.00', 2),
(43, 'Camisa Indigo Talla XL', '50.00', '75.00', 2),
(44, 'Jacket Beige S', '200.00', '250.00', 4),
(45, 'Jacket Beige M', '200.00', '250.00', 4),
(46, 'Jacket Beige L', '200.00', '250.00', 4),
(47, 'Jacket Beige XL', '200.00', '250.00', 4),
(48, 'Jacket Coral S', '200.00', '250.00', 4),
(49, 'Jacket Coral M', '200.00', '250.00', 4),
(50, 'Jacket Coral L', '200.00', '250.00', 4),
(51, 'Jacket Coral XL', '200.00', '250.00', 4),
(52, 'Jacket Cyan S', '200.00', '250.00', 4),
(53, 'Jacket Cyan M', '200.00', '250.00', 4),
(54, 'Jacket Cyan L', '200.00', '250.00', 4),
(55, 'Jacket Cyan XL', '200.00', '250.00', 4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `user`
--

CREATE TABLE `user` (
  `UserID` int(11) NOT NULL,
  `BirthDate` date DEFAULT NULL,
  `Email` varchar(100) NOT NULL,
  `Address` varchar(100) CHARACTER SET cp1250 COLLATE cp1250_bin DEFAULT NULL,
  `PostalCode` varchar(5) DEFAULT NULL,
  `Password` varchar(50) NOT NULL,
  `City` varchar(50) DEFAULT NULL,
  `State` varchar(50) DEFAULT NULL,
  `FullName` varchar(50) NOT NULL,
  `LastAccess` date DEFAULT NULL,
  `Enabled` int not null
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `user`
--

INSERT INTO `user` (`UserID`, `BirthDate`, `Email`, `Address`, `PostalCode`, `Password`, `City`, `State`, `FullName`, `LastAccess`,`Enabled`) VALUES
(1, NULL, 'Herman@suite.com', '', NULL, '', NULL, NULL, 'Herman Finn', '2021-03-01', 0),
(2, NULL, 'Adam@smith.com', NULL, NULL, '', 'New York', NULL, 'Adam Smith', '2021-03-01', 1),
(3, NULL, 'jack@blue.com', NULL, NULL, '', 'Seattle', NULL, 'Jack Blue', '2021-03-01', 0),
(4, NULL, 'William@Foo.com', NULL, NULL, '', 'Houston', NULL, 'William Defoe', '2021-03-01', 0),
(5, NULL, 'Burt@Feynolds.com', NULL, NULL, '', 'Pasadena', NULL, 'Burt Feynolds', '2021-03-01', 0),
(6, NULL, 'Martin@outlook.es', NULL, NULL, '', 'Tampa', NULL, 'Martin King', '2021-03-01', 0),
(7, NULL, 'John@microsoft.com', NULL, NULL, '', 'Orlando', NULL, 'John Atbukle', '2021-03-01', 0),
(8, NULL, 'Catherine@redhat.com', NULL, NULL, '', 'Miami', NULL, 'Catherine Duck', '2021-03-01', 1),
(9, NULL, 'Edmundo@linux.com', NULL, NULL, '', 'Atlanta', NULL, 'Edmundo Valdés', '2021-03-01', 0),
(10, NULL, 'Terry@linux.com', NULL, NULL, '', 'San Luis', NULL, 'Terry Hatchet', '2021-03-01', 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `setup`
--

CREATE TABLE `setup` (
  `Host` varchar(50) NOT NULL,
  `Autenticación` int(11) NOT NULL,
  `SuperAdmin` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `setup`
--

INSERT INTO `setup` (`Host`, `Autenticación`, `SuperAdmin`) VALUES
('localhost', 1, 3);


--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `category`
--
ALTER TABLE `category`
  ADD PRIMARY KEY (`CategoryID`);

--
-- Indices de la tabla `product`
--
ALTER TABLE `product`
  ADD PRIMARY KEY (`ProductID`),
  ADD KEY `FK_PRODUCT_CATEGORY_CATEGORY` (`CategoryID`);

--
-- Indices de la tabla `setup`
--
ALTER TABLE `setup`
  ADD KEY `SuperAdmin` (`SuperAdmin`);

--
-- Indices de la tabla `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`UserID`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `product`
--
ALTER TABLE `product`
  MODIFY `ProductID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=56;

--
-- AUTO_INCREMENT de la tabla `user`
--
ALTER TABLE `user`
  MODIFY `UserID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `product`
--
ALTER TABLE `product`
  ADD CONSTRAINT `FK_PRODUCT_CATEGORY_CATEGORY` FOREIGN KEY (`CategoryID`) REFERENCES `category` (`CategoryID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `setup`
--
ALTER TABLE `setup`
  ADD CONSTRAINT `setup_ibfk_1` FOREIGN KEY (`SuperAdmin`) REFERENCES `user` (`UserID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
