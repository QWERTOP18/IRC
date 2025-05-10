/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:19:08 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 09:19:09 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server/Server.hpp"
#include "Model/Model.hpp"
#include "Controller/Controller.hpp"

int main(int argc, char **argv)
{
    Model model;
    Controller controller(&model); // IO以外のモデル操作
    try
    {
        if (argc != 3)
            throw std::invalid_argument("Usage: ./IRC <port> <password>");
        Server server(argv[1], argv[2], &model, &controller);
        server.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
}
